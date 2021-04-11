# Explicit Sepcialization

- Useful when we have to compare the value within the addresses not the
  address itself.
- Template specialized for a particular type
- Provides correct semantics for some datatype.
- Explicitly speicialized function must be defined in a .cpp file. (Not in
  header file)
- Primary template definitions should occur before specialization.
- You should use `template<>` prefix to indicate that it is explicit
  spcialization.

### Example
```cpp
// Primary Template
template<typename T>
T Max(T arg){
  return x > y ? x : y;
}

// Explicit Speicialization
template<> const char* Max <const char*> (const char* x, const char* y){
  return strcmp(x,y) > 0 ? x : y;
}

int main() {
  const char* a{"A"};
  const char* b{"B"};
  auto s = Max(a,b);
  std::cout << s << std::endl;
  return 0;
}
```