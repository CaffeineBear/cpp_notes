# Friend Class

## Friend Class for operator overloading

- If we are trying to access the private member from the global overloading functions, the compiler complains.
- We can resolve this via `friend` statement.
- A `friend` of a class has the access to all members of the class.
- this can be done in class declaration.


### Example
```cpp
// In header file
class Integer {
  // ... some code
  friend std::istream & operator>> (std::istream input, Integer & a);
}

// In source file
std::istream & operator>> (std::istream input, Integer & a) {
  int x;
  input >> x;
  *a.m_pInt = x;
  return input;
}

// In main
int main() {
  Integer a(1);
  std::cin >> a;
}
```

## Friend Class other than \<iostream\>

### Example
```cpp
// In header file
class Integer {
  // ... some code
  friend std::istream & operator>> (std::istream input, Integer & a);
  friend class Printer;
}

class Printer {

}
```

## Notes
- the usage of the friend class is discoraged because it has access to all of the member properties.
- This could become the source of the bug.
