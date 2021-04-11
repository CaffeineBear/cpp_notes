# User Defined Literals
- a fixed value that appears directly in the code.
- supported literals: integer, floating, boolean, character string
  - can be modified by using prefixes or suffixes
- C++11: **User defined literals** are supported.
  - allows syntatic shortcuts
  - increase type safety.
  - e.g. `Temperature temp{82.5_F}` -> defined Farenheit.


## Syntax
```cpp
<return_type> operator"" _<literal>(<arguments>)
```
- operator followed by empty double quotes.
- `<return_type>` can be any type including void
- `_<literal>`: starts with underscore followed by name.
- `<arguments>` can be following types only:
  - integer - unsigned long long
  - floating - long double
  - character - char, wchar_t, char16_t, char32_t
  - string - const char*
  - types above are the largest data types which can be stored.

## Example
```cpp
class Distance {
private:
  long double m_Kilometers;
public:
  Distance(long double km) :m_Kilometers{km} {

  }
  long double GetKm()const {
    return m_Kilometers;
  }
  void SetKm(long double val){
    m_Kilometers = val;
  }
};

Distance operator"" _mi(long double val){
  return Distance{ val * 1.6 };
}

int main() {
  using namespace std;
  Distance dist{32.0_mi}; // converting miles to kilometers
  std::cout << dist.GetKm() << std::endl;
  return 0;
}
```

## Important Notes
- Custom literals should begin with undesrscore.
  - other literals are reserved by the standard library.
- You can not redefine the built-in literal suffixes.
  - only following types: unsiged long long, long doubles, const char*, char
- Literal operator functions cannot be member function but global.