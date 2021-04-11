# String Literals ( Raw String Literals)
- There are escapce sequence in string. `"\n"`, `"\t"` and etc.
- For the compiler to interpret whole string without the escape sequence,
  you can use string literals by adding `R"()"` suffixes.
- Use this for long string.
- You should add DELIMITER as it can't escape brackets and double comma.
- Only from C++17.

## Syntax
```cpp
R"<YOUR_DELIM>(any string including bracket like () this.)<YOUR_DELIM>"
```