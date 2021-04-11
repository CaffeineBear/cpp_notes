# Static Assert

- It can check the expression in compilation time.
- It is useful when you don't want the program to compile when it is in
  64bits.
- This can combine with typetraits to prevent compiling if the types
  were not supported.

### Example
```cpp
int main(){
  static_assert(sizeof(void*) == 4), "Compile in 32-bit mode only";
}
