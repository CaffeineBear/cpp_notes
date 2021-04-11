# Cpp string, std::string
- Returning local pointer variable from the function has no gurantee that it
  will be available after the function has returned.
- Working with C type string is error prone and complex.
- In C style string, the querying the length takes liner time while C++ string
  will cache it to have constant time.


## Useful member function
  - `strVarName.insert(position, string)`
  - `strVarName.erase(start, end)`
  - `strVarName.clear()` is same as `strVarName.erase()` without argument.
  - `strVarName.find("substr", start)` to return index position where it found.
  - `strVarName.c_str()` returns the C style string.

## Furthernote
  - Always prefer direct initialization `{}`
  - You can also futher type of literals with suffixes.
    - First  you need to use namespace as `using namespace std::string_literals;`
    - Then you use something like: `std::string str = "Some Str"u`
    - `auto` will reduce the syntatic noise further.

