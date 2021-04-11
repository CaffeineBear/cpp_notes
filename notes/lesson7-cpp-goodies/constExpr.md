# Constant Expression - constexpr
- Increase the performance of the code as the computation is done at the compile time.
- Note: not all constant variables are computed at compile time. So, to do computation at compile time, you need to use **constexpr**.
- This is useful when the function returns the constant.

## Example
```cpp
constexpr int GetNumber(){
  return 42;
}

constexpr int Add(int x, int y){
  return x + y;
}

constexpr int Max(int x, int y){
  return x > y ? x : y;
}

int main() {
  // behaves like const expr function
  constexpr int i = GetNumber();
  int arr[i]; // the size of array initialized at compile time.

  const int j = 5;
  int arr1[j]; // the size of array is initialized only running time.

  // still behaves like const expr funciton because of `const` keyword.
  const int k = GetNumber();

  // behaves like a normal function.
  int x = GetNumber();

  // behaves like const expr function (since we used literals)
  constexpr int sum = Add(12, 13);

  // compile error (since one of them is not constexpr)
  constexpr int sum = Add(x, 13);

  return 0;
}
```

## Constant Expressioon Rules
1. Should accept and return literal types only.
    - void, scalar types(int, float, char), references and etc.
2. Should contain only a single line statement that should be a return statement.

3. constexpr functions are implicitly inline. ( meaning you have to write
   it like inline function)

## When to use constexpr or cosnt?
- All `constexpr` variables are `const`, but not the other way round.
- Use `cosntexpr` to create expressions that can be evaluated at compile time.