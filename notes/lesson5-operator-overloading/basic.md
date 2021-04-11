# Operator Overloading
- custom implementation for primitive operators
- usage of user-defined objects with math expression
- Can be implemented as member or global functions.
- syntax: `<ret> operator <#> (<arguments>) `
- For global: no of operands  = no of arguments.
- For member: one operand is passed as argument.
  - binary operator needs only one explicit argument.
  - unary opartor don't need any argument.
  - e.g.
  - In global: `Integer operator +(const Integer &, const Integer &)`
  - In member: `Integer Integer::operator +(const Integer &)`

## Member Example
```cpp
// header
class Integer {
  Integer operator +(const Integer & a) const;
  // other code...
}

// source
Integer Integer::operator+(const Integer & a) const {
  Integer temp;
  * temp.m_print = *m_pInt + *a.m_pInt;
  return temp;
}
```

## Global Example
```cpp
Integer operator+(const Integer & a, const Integer & b) {
  Integer temp;
  temp.SetValue(a.GetValue() + b.GetValue());
  return temp;
}
```

## More example
```cpp
// header
class Integer {
  Integer & operator ++ (); // pre-increment does not have any argument.
  Integer opeartor ++ (int); // post-increment of any argument to overloading member name.
  bool opeartor ==(const Integer &obj) const;
}

// In source code
// for PRE-increment
Integer & Integer::operator++() {
  ++(*m_pInt);
  return *this; // should return the value at the address of this.
}

// for POST-increment - return the value first and increment
Integer Integer::operator++(int) {
  Integer temp(*this);
  ++(*m_pInt);
  return temp; // since it is the temporary variable, it should not return reference.
}
// Therefore, pre-increment is more efficient because post-increment always need the temporary object.

// for bool.
bool Integer::operator==(const Integer &obj) const {
  return (*m_pInt == *obj.m_pInt);
}
```