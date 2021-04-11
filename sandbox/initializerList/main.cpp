#include <iostream>
#include <initializer_list>
#include <cassert>

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