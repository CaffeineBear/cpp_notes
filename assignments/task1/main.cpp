#include <iostream>
#include <cassert>

int Add(int *a, int *b) ;    //Add two numbers and return the sum
void AddVal(int *a, int *b, int *result); //Add two numbers and return the sum through the third pointer argument
void Swap(int *a, int *b) ;  //Swap the value of two integers
void Factorial(int *a, int *result);       //Generate the factorial of a number and return that through the second pointer argumen

using namespace std;

int main() {
  int x,y,z;
  int *ptr1, *ptr2, *ptr3;
  x = 4;
  y = 5;
  z = 10;
  ptr1 = &x;
  ptr2 = &y;
  ptr3 = &z;
  // Testing simple addition referring to variable.
  assert(Add(ptr1,ptr2) == 9);

  // Testing result is changed after addition.
  AddVal(ptr1,ptr2,ptr3);
  assert(*ptr3 == 9);
  assert(z == 9);

  // Testing value has been swapped.
  Swap(ptr1, ptr2);
  assert(*ptr1 == 5);
  assert(*ptr2 == 4);

  // Test factorial result is saved
  Factorial(ptr1, ptr3);
  assert(*ptr3 == 1*2*3*4*5);
  *ptr1 = 0;
  Factorial(ptr1, ptr3);
  assert(z == 1);

  cout << "Passed all test"  << endl;
  return 0;
}

int Add(int *a, int *b) {
  return *a + *b;
}
void AddVal(int *a, int *b, int *result) {
  *result = *a + *b;
}
void Swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void Factorial(int *a, int *result) {
  if( *a == 0 ){
    *result = 1;
    return;
  }
  for(int i = 1; i <= *a; i++){
    if( i == 1 ){
      *result = 1;
    }
    *result = *result * i;
  }
}