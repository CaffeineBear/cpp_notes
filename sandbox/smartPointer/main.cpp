#include <iostream>
#include <memory>
class Integer {
  int *m_pInt = nullptr;
public:
  Integer() {
    std::cout << "Integer()" << std::endl;
  }
  Integer(int x) {
    std::cout << "Integer(int x): " << x <<  std::endl;
    m_pInt = new int(x);
  }
  ~Integer(){
    std::cout << "~Integer()";
    if( m_pInt != nullptr ){
      std::cout << " - Removing: " << *m_pInt;
    }
    std::cout << std::endl;
    delete m_pInt;
    return;
  }
  Integer & operator= (const Integer && a ){
    std::cout << "operator=" << std::endl;
    if(m_pInt == nullptr){
      m_pInt = new int(*a.m_pInt);
    }
    return (*this);
  }
  Integer & operator=( Integer && a ){
    std::cout << "move from the addres of ";
    std::cout << *a.m_pInt << " to " << *m_pInt << std::endl;

    if( this != &a ){
      delete m_pInt;
      m_pInt = a.m_pInt;
      a.m_pInt = nullptr;
    }
    return *this;
  }
  Integer(Integer && obj) {
    std::cout << "Integer(int&&)" << std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
  }
  int GetValue(){
    return *m_pInt;
  }
};

void Display(Integer *p){
  if( !p ){
    return;
  }
  std::cout << "Display: " << p->GetValue() << std::endl;
}

void Operate() {
  using namespace std;
  unique_ptr<Integer> p{new Integer(5)};
  Display(p.get());
  // cout << "freeing" << endl;
  // p = nullptr;
  cout << "-----reset()-------" << endl;
  p.reset(new Integer{9});
  Display(p.get());
  cout << "----------ASSIGNMENT--------" << endl;
  cout << "*p = 10" << endl;
  *p = 10;
  Display(p.get());
  cout << "----------END-----------" << endl;
}

int main() {
  Operate();
  return 0;
}