# Copy Elision
-  (compilation) An optimisation technique where a value is transfered to
 the final target address, instead of being copied and then destroyed.
- It is used to eliminate temporary object in C++.
- Visual Studio automatically process copy elision and you can not turn it off.
- To exclude copy elision in Linux, type in command line: `g++ -fno-elide-constructors someSourceFiles.cpp`.
- Otherwise, the most compilers will have them by default.
- If temporary object is returned by value in the function, the move construnctor will be invoked.
- For copy elision to work, the class should contain copy and move constructor. ( Note: there are changes in C++17 )

## Example
```cpp
// Named return value optimization
Integer Add(int i, int b){
  Integer temp(a + b);
  return temp;
}

// Return value optimization
Integer Add(int i, int b){
  return Integer(a + b);
}
```
