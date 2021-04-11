## Reference type
- an alias for variable
- created with `&` operator during declaration phase.
- it always need initializer aka referent.
- The referent should always be a variable. (except for few cases, it can not be the literal)
- bound to its referent: you cannot make the reference bind to some other variable.
- you can modify a variable indirectly like a pointer but the reference itself is not a new variable.
- Therefore, no memory is allocated for reference.
```cpp
// Referent
int x = 10;
// Reference
int &ref = x; // x is the referent.
cout << "x: " << x << endl;
cout << "ref: "<< ref <<endl;
// They should both print 10.
// Modifying either ref or x will change the both of the value.
// They should also have the same memroy address
cout << "mem x: " << &x << endl;
cout << "mem ref: "<< &ref <<endl;

// Since ref is binded to x, it can not be changed.
int y = 9;
ref = y;
ref = 8; // now the value of x and ref are still 8 while the value of y is unchaged.
```

- If we dont give any initializer to the reference, the compiler throws an error.


## Difference between Reference and Pointer
|Reference | Pointer |
| -------- | ------- |
| - Always needs an initializer | - It is optional |
| - The initializer must be an lvalue | - No need to |
| - Cannot be nullptr | - can be |
| - bound to its referent | - can point to other variables|
| - No storage is requried | - it has own storage |
| - Do not need to deference the value | - Needs to dereference it to use |


## Reference VS Pointer
- References are easier to read.
- The pointer always have to check whether it is `nullptr` because the compiler cannot catch it in some cases.
```cpp
void Print(int *ptr){
  using namespace std;
  // if ptr is nullptr this program clashes without the compiler warning.
  cout << *ptr << endl;
}
```