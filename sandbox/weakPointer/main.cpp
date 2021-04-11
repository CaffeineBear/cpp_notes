#include <iostream>

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

