# Non-Type Template Argument.

- Should be constant expression because it will only put values at compile
  time.
  e.g. `Print<3>();` and `Print<sizeof(i)>();` works while `Print<i>();`
  does not work.
- Also, the argument is constant. Hence, you can not modify them in the
  template implementations.
- Non-type template arguments are more common with classes but with
  functions, they are commonly used with arrays.


### Example
```cpp
template<typename T>
T Sum(T *arr, int size) {
  T sum{};
  for(int i = 0; i < size; i++){
    sum += parr[i];
  }
  return sum;
}

template<typename T, int size>
T SumNonType(T (&parr)[size] ) {
  T sum{};
  for(int i = 0; i < size; i++){
    sum += parr[i];
  }
  return sum;
}

int main(){
  int arr[] {3,1,9,7};
  int sum = Sum(arr, 4);
  std::cout << sum << std::endl;

  // note that we need to specify the size here.
  // int (&ref)[4] = arr;

  // However, using non type template argument,
  // we don't have to specify the size explicitly
  int sum2 = SumNonTeyp(arr);
  std::cout << sum2 << std::endl;

  return 0;
}
```

## Further notes
- Since the non-type arguments are computed at compile time, you need to
  give a constant expression. (addresses, references, integrals, nullptr,
  enums).
  - For addresses, they should be from static memory. Meaning that the
    addresses you put should not be dynamic address. But it should rather
    be a address of function or variable which could be obtained at compile
    time.
- `std::begin()` and `std::end()` uses non template arguments.
- Non-type arguments are also a type.
  - e.g. `Stack<float, 9>` is not the same type as `Stack<float, 10>`.