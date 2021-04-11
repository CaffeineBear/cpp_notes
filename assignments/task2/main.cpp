#include <iostream>
#include <cassert>

void Add(int a,int b, int &result) ;    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int &result) ;    //Find factorial of a number and return that through a reference parameter
void Swap(int &a, int &b) ;            //Swap two numbers through reference arguments

using namespace std;

int main() {
  int x = 3, y = 4, z = 5;
  int &ref1 = x;
  int &ref2 = y;
  int &ref3 = z;

  // Testing simple addition referring to variable.
  Add(ref1,ref2, ref3);
  assert(z == 7);

  // Testing value has been swapped.
  Swap(ref1, ref2);
  assert(x == 4);
  assert(y == 3);

  // Test factorial result is saved
  Factorial(ref1, ref3);
  assert(z == 1*2*3*4);
  ref1 = 0;
  Factorial(ref1, ref3);
  assert(z == 1);

  cout << "Passed all test"  << endl;
  return 0;
}

void Add(int a,int b, int &result) {
  result = a + b;
}
void Factorial(int a, int &result) {
  if( a == 0 ){
    result = 1;
    return;
  }
  for(int i = 1; i <= a; i++){
    if( i == 1 ){
      result = 1;
    }
    result = result * i;
  }
}
void Swap(int &a, int &b) {
  int temp = b;
  b = a;
  a = temp;
}
