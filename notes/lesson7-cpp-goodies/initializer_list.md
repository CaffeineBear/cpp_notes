# std::initializer_list
- it is used for user-defined containers to initialize with uniform
  initializer.
  - e.g. `<SomeContainer> container(initial_lists);`
  - `Bag b {1,2,3};`
- To use this, you need to have constructor which accepts
  `std::initializer_list` as argument.
  - e.g. `Bag(std::initializer_list<int> values)`;
- This is often used with iterators.
- A brace list of elements automatically creates an initializer list object.
- An initializer_list also provides range based forloop.

## More notes
- lightweight proxy object that represents an array of objects.
- This library is used when you call `auto`, ranged forloop, listed
argument construtor and a function.
- Note: it is not a true container but has a similar behaviour.


## Example
```cpp
class Bag {
private:
  int arr[10];
  int m_size{};
public:
  Bag(std::initializer_list<int> values) {
    assert(values.size() < 10);
    auto it = values.begin();
    while( it != values.end() ){
      Add(*it);
      ++it;
    }
  }
  void Add(int value) {
    assert(m_size < 10);
    arr[m_size++] = value;
  }
  void Remove(){
    --m_size;
  }
  int operator[] (int index){
    return arr[index];
  }
  int GetSize()const {
    return m_size;
  }
};


int main() {
  Bag b{3,1,8};
  for (int i = 0; i < b.GetSize(); i++) {
    std::cout << b[i] << std::endl;
  }
  return 0;
}
```