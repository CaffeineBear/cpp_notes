# Enums

- It will create a restricted range of values -> **Symbolic constants**
- Internally, it is represented as undefined integral types.
- Can be implicitly converted to `int` type but not the other way around.
- Default value is zero and subsequent ones are incremented by one.


## Example
```cpp
enum Color{RED, GREEN, BLUE};
void FillColor(Color color){

}

int main() {
  Color c = RED;
  FillColor(c);
  // You can't do this an integer does not implicitly convert to enum type.
  // FillColor(5);

  // However, you can do static casting.
  FillColor(static_cast<Color>(2));
}
```

## Scoped Enum
- The scope of the enumerator is the same as that of its type.
  - You can create your own sope with `class` keyword.
  - e.g. `enum class Color{RED, GREEN, BLUE};`

```cpp
enum class Color{RED, GREEN, BLUE};
enum class TrafficLight{RED, GREEN, BLUE};

int main() {
  Color c = Color::RED;
}
```

## Initializing Enum values and specifying integral types.
- `enum class Color : int{RED = 5, GREEN, BLUE};`

## Why is Scoped enum better than non-scoped?
1. Scoped enums use int as the underlying type which improve portability
   accross different c++ compilers
2. Scoped enums do not pollute the global namespace with enumerator names.
3. increased redability.