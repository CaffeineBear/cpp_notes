#include <iostream>

void Print(int &x){
  std::cout << x << std::endl;
  x = 2;
}

int main() {
  int i = 1;
  using namespace std;
  cout << "hello world";
  cout << i << endl;
  Print(i);
  Print(i);
}