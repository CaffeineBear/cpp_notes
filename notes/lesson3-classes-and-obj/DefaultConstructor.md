# Default Constructor
- if you have  paramatrized while you don't have default constructor, the compiler will complain.
- However, in C++11, you can avoid this by having initializer declared at member properties and having `default` assignment.
```cpp
class Integer {
  int m_value = 0;
public:
  Integer() = default;
  Integer(int value) {
    m_value = value;
  }
}
```
- You can use `default` statment only on: **construcor, destructor, copy constructor**.

<br/>
<br/>

# Delete keyword
- If you want others to not synthesize copy constructor, you can assign `delete` statement.
- Unlike `default` statement, this can be used in any other member methods.
```cpp
class Integer {
  Integer(const Integer &obj) = delete;
}
```
