# Weak Pointers

```cpp
class Printer {
  int *m_pValue{};
public:
  void SetValue(int *p){
    m_pValue = p;
  }
  void Print() {
    std::cout << "Value is: " << *m_pValue << std::endl;
  }
};

int main() {
  Printer prn;
  int num{};
  std::cin >> num;
  int *p = new int{num}  ;
  prn.SetValue(p);
  if(*p > 10){
    delete p; // Printer's member property is deleted.
    p = nullptr;
  }
  // when calling this function, you trying to access the one that
  // is already released when *p > 10.
  prn.Print();
  delete p;
  return 0;
}
```

- So, in `Print()` function, we need to check whether `*m_pValue` is valid or not.
- Can we compare against the `nullptr`?
  - No. The pointer variable is assigned to `nullptr` at `main()` function while
  Printer function has the old address.
- So we need some communication between those pointer variable. Manual implementaion
  is hard.

## Using Shared Pointer

```cpp
class Printer {
  std::shared_ptr<int> m_pValue{};
public:
  void SetValue(std::shared_ptr<int> p){
    m_pValue = p;
  }
  void Print() {
    std::cout << "Ref Count: " << m_pValue.use_count() << std::endl;
    std::cout << "Value is: " << *m_pValue << std::endl;
  }
};

int main() {
  Printer prn;
  int num{};
  std::cin >> num;
  std::shared_ptr<int> p{new int{num}};
  prn.SetValue(p);
  if(*p > 10){
    p = nullptr;
  }
  prn.Print();
  return 0;
}
```
- The code above solves the problem however, `p = nullptr;` does not release all
  the memory. (reference count is not zero)
- It will only released when the `Printer` object is destroyed.
- What if `Printer` object is expensive resource? -> you need to release earlier.
- We need a way that the `m_pValue` to access `p`.
- We can then use **Weak Pointer**.


## Weak Pointer, std::weak_ptr
- Internally, the `shared_ptr` will create a control block which contains the
  information like reference counter and etc.
- A `weak_ptr` will point to this control block.
- Although the `shared_ptr` is delted, the `weak_ptr` will still point to the
  control block to tell the reference count is zero.
- The control block is destroyed when the `weak_ptr` is destroyed.
- This means you can have multiple `weak_ptr` pointing to the same control blcok of a `shared_ptr`.

### Syntax
```cpp
std::shared_ptr<type> pName{ initialization };
std::weak_ptr<type> wkName = pName;
```
- You can only check whether the reference counter of a control block is zero by
  calling `expired()` function.
- To access the `shared_ptr`, you should call `lock()` from the `weak_ptr`.
  - `lock()` will increment the reference by 1 and return a `shared_ptr`.

### Example
```cpp
class Printer {
  std::weak_ptr<int> m_pValue{};
public:
  void SetValue(std::weak_ptr<int> p){
    m_pValue = p;
  }
  void Print() {
    if( m_pValue.expired() ){
      std::cout << "Resource is no longer available" << endl;
      return;
    }
    auto sp = m_pValue.lock();
    std::cout << "Value is: " << *sp << std::endl;
    std::cout << "Ref Count: " << sp.use_count() << std::endl;
  }
};
```


### Further Note
- The weak pointer does not increase the reference count.
- The weak pointer is also used to avoid circular reference.

