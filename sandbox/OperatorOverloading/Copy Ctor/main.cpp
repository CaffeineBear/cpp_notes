#include "Integer.h"
#include <iostream>
#include <memory>
// class IntPtr {
// 	Integer *m_p;
// public:
// 	IntPtr(Integer *p) :m_p(p) {

// 	}
// 	~IntPtr() {
// 		delete m_p;
// 	}
// 	Integer *operator ->() {
// 		return m_p;
// 	}
// 	Integer & operator *() {
// 		return *m_p;
// 	}
// };
// void CreateInteger() {
// 	std::unique_ptr<Integer> p(new Integer);
// 	//auto p2(p);
// 	(*p).SetValue(3);
// 	//std::cout << p->GetValue() << std::endl;
// }
// void Process(Integer val) {

// }

// int main() {
// 	Integer a(3);
// 	/*auto b(std::move(a));
// 	std::cout << a << std::endl;*/
// 	Process(std::move(a));
// 	return 0;
// }
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
  *p = 10;
  Display(p.get());
  cout << "----------END-----------" << endl;
}

int main() {
  Operate();
  return 0;
}