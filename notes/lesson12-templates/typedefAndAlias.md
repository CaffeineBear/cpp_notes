# Type def and Alias

## Typedef

- Useful to construct shorter or more meaningful names for existing types.
- Simplifies declaration of some types. (e.g. templates)
- Implementation details that may change can be encapsulated without affecting the client code.
- Note: it is not a new type. it only gives a new name for existing type.

### Example
```cpp
typedef unsigned int UNIT;
typedef long long LLONG;
typedef std::vector<std::list<Employee>> Teams;
typedef const char* *(ErrorFn)(int);
```



## Type Alias

- Created through `using` keyword.
- `using identifier = type;`

### Example
```cpp
using UNIT = unsigned int;
using LLONG =long long;
using Teams = std::vector<std::list<Employee>>;
using ErrorFn = const char* (*)(int);
```

## Type Alias vs typedef
- you can tempetize alias while typedef you can't
### Example
```cpp
template<typename T>
using Names = std::vector<std::list<T>>;
int main() {
  Names<std::string> names;
}
```