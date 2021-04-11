# Const Qualifier

- once declared, it cannot be modified.
- any attempt for modifying const variable will be thrown an error by the compiler.
- It always need a initialization.
- This replaces macros in C. And const is better than macros since it is not type safe.
- The code becomes more readable and ensures that the nobody can modify it.
- You cannot store the address of `const` variable because it might get dereference for the changes.
- To store the address of the `const` variable to the pointer, the pointer itself has to be a constant.
- You can make the pointer itself to be constant: `const int *const ptr = someVariable`. Once you have done this, you are not able to change the address as well.


## Printing reference
```cpp
void Print(const int &ref){
  using namespace std;
  cout << ref << endl;
}
int main(){
  int x = 5;
  Print(x);
  Print(3);
}
```
- By using the `const` declaration in input, you can now also print literal. Otherwise, the compiler complains that it is invalid `lvalue`.