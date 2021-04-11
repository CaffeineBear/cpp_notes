# Name Spaces
- A named region for declaring types.
- The types are not visible outside the namespace.
- For standard library, we use `std` name space.
- This is used to prevent the name clashes.
- If the programmer created types which has the same name, the `namespace` is useful.
- This also helps modularize the code.
- Format:
```cpp
namespace<name> {
  (namespace, class, structure, funciton, variable and etc)
}
```
- You can open the entire `namespace` however, this is usually not the good practice.
- You should open specific type. eg. `using std::cout;`.
- You can optionally choose to put full qualified name like `std::cout << someVar << std::endl;`
- `::` is called the scope.

## Example Code
```cpp
namespace Avg{
  float Calculate(float x, float y) {
    return (x + y) / 2;
  }
}

namespace Basic {
  float Calculate(float x, float y) {
    return x + y;
  }
}

int main {
  using namespace Avg;
  // or using Avg::Calculate;
  Calculate(3.9f, 8.2f);
  return 0;
}
```
- You can also nest the namespace:
```cpp
namespace Sort {
  void QuickSort() {

  }
  void MergeSort() {

  }
  ...
  namespace Comparison {
    void Less() {

    }
    void Greater() {

    }
  }
}
```

- `namespace` without the name?
- It is only visible in that scope where namespace is declared.
- This namespace is not accessible in other source file.
```cpp
namespace{
  void Internal() {

  }
}
int main () {

}
```

## Further note
- Namespace prevent name clashes. Opening an entire namespace globally will defeat the purpose of namespace