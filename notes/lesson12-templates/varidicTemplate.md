# Variadic Templates

- A function that can have many arguments.
- The problem with `initializer_list` is that it has to be the same type.
- Using variadic templates, we can resolve this.
- You need to use `...` ellipsis.
  - it will create a pack of Template types.
  - it will automatically expanded by the compiler.
- You can not access the individual arguments directly but you should use
  function recursion.
  - For end condition, you should write another function without variadic
    template. (It is called base case function)
  - To do this, we need to pass one more typename and a function with
    empty argument.
  - For some cases, we might to know the last element and it is done via
    `sizeof...(args)` to indicate remaining number of parameter.
  - IMPORTANT: you should make it **constant reference** to avoid making
    copy.
  - Or BETTER WAY: We also need perfect forwarding for any arguments.

### Example
```cpp
// Base case
void Print() {
  std::cout << endl;
}

template<typename T, typename ...Params>
void Print(T &&a, Params&&... args){
  std:: cout << a;
  if(sizeof...(args) != 0) {
    std::cout << ",";
  }
  Print(std::forward<Params>(args)...);
}
int main() {
  Print(1, 2.35, "4");
  return 0;
}
```
