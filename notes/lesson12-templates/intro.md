# Template

- To create a generic type function/class.
- The compiler will substitute the type automatically.
- If the template is not used at all, the compiler will not generate code.
- Use of templates will lead to high performance algorithms and classes.
- no runtime cost is involved.

### Example
```cpp
template<typename T>
T Max(T x, T y){
  return x > y ? x : y;
}
```

## Some High performing C++ libraries
- These used templates
- ATL, WTL, Boost, POCO, ACE.

## Function templates
```cpp
template<typename T>
T Max(T arg){
  return x > y ? x : y;
}
```
- Template type argument is called `typename`.
- Each type names is a placeholder for the actual type.