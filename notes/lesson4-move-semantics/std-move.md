# std::move
- It forces the compiler to use move semantics instead of copy semantics.


## Example
```cpp
int main() {
  Integer a(1);
  auto b{a}; // by default this will trigger copy constructor.
  return 0;
}

// Method1.  - static_cast to cast it to move constructor -> hard to read.
int main() {
  Integer a(1);
  auto b{static_cast<Integer&&>(a)};
  return 0;
}

// Method2. - using std::move -> much easier to read.
int main() {
  Integer a(1);
  auto b{std::move(a)};
  return 0;
}
```

## Why do we use it
- If one object is no longer used while the contents of it is useful for other class or object, we can `move` it instead of `copy` for the performance.
- Note: after you move one object to other, you should not use the original one. But you can always re-initialize it if you want to use it again.