# Class Templates

- When the implementation is outside of class template, you need to
  specify full notation rather than short notation.
- A shorthand notation only works within the class not the outside.
  - You can't do:
    ```cpp
    // In source file
    template<typename T, int size>
    Stack Stack<T, size>::Create() {
      return Stack<T,size>();
    }
    ```
  - In here, `Stack` return will not work because each typename combination
    is a part of the class type.
  - So you should use:
    `Stack<T, size> Stack<T, size>::Create(){/* code */}`

### Example
```cpp
template<typename T, int size>
class Stack {
  T m_buffer[size];
  int m_top{-1};
public:
  Stack() = default;
  Stack(const Stack &obj){
    m_top = obj.m_top;
    // since m_top starts from -1,
    for(int i = 0; i <= m_top ; i++){
      m_buffer[i] = obj.m_buffer[i];
    }
  }
  void Push(const T & elem){
    m_buffer[++m_top] = elem;
  }
  T Pop();
  const T& Top()const {
    return m_buffer[m_top];
  }
  bool IsEmpty(){
    return m_top == -1;
  }
  Stack Create();
};

template<typename T, int size>
T Stack<T, size>::Pop(){
  return m_buffer[--m_top];
}

template<typename T, int size>
Stack Stack<T, size>::Create() {
  return Stack<T,size>();
}

int main(){
  Stack<float, 10> s;
  s.Push(1);
  s.Push(2);
  s.Push(3);
  s.Push(4);
  auto s2(s);
  while(!s2.IsEmpty()){
    std::cout << s2.Top() << std::endl;
    s2.Pop();
  }
}
```

## Explicit Specialization
- For some types like `char*` you need to have special type for the
  template to work properly.
- You can do that by providing a type.
- Also, you can specialized on some of members by having definitions
  outside the class.
  - This might be useful `vector<int>` type because it only needs to
    change Print() funciton as `vector` does not overload `<<`.


### Example
```cpp
// General
template<typename T>
class PrettyPrinter {
  T *m_pData;
public:
  PrettyPrinter(T *data): m_pData(data){

  }
  void Print(){
    std::cout << "{" m_pData << "}" << std::endl;
  }
  T* GetData() {
    return m_pData;
  }
};

// Explicit Specialization: Print() specialized for vector<int>
template<>
void PrettyPrinter<std::vector<int>>::Print() {
  std::cout << "{";
  for(const auto &x : *m_pData){
    std::cout << x;
  }
  std::cout << "}";
}

// Explicit Specialization: T is specialized to char*.
template<typename T>
class PrettyPrinter<char*> {
  char* m_pData;
public:
  PrettyPrinter(T *data): m_pData(data){

  }
  void Print(){
    std::cout << "{" m_pData << "}" << std::endl;
  }
  char* GetData() {
    return m_pData;
  }
};

int main(){
  char* p{"Hello world"};
  PrettyPrinter<char*> p3(p);
  p3.Print();
  return 0;
}
```
<br />
<br />


## Partial Specialization.
- Explicit specialization specializes all template parameters while
  partial specialization specializes only some template parameters.
- Following example does not remove `T` but specialized to array of `T`.

```cpp
template<typename T>
class SmartPointer {
	T *m_ptr;
public:
	SmartPointer(T *ptr) :m_ptr(ptr) {

	}
	T * operator ->() {
		return m_ptr;
	}
	T & operator *() {
		return *m_ptr;
	}
	~SmartPointer() {
		delete m_ptr;
	}
};
//Partial specialization for array types
template<typename T>
class SmartPointer<T[]> {
	T *m_ptr;
public:
	SmartPointer(T *ptr) :m_ptr(ptr) {

	}
	T & operator[](int index) {
		return m_ptr[index];
	}
	~SmartPointer() {
		delete[] m_ptr;
	}
};
int main() {
	SmartPointer<int[]> s1{ new int[5] };
	s1[0] = 5;
	std::cout << s1[0] << std::endl;
	return 0;
}
```