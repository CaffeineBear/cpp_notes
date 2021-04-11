# Assignment Operator

- By default, assignment operator uses shallow copy.
- So we need to implement them to perform a deep copy.

## Example
```cpp
// header
class Integer {
  Integer & operator =(const Integer &a);
}

// source
Integer & Integer::Integer operator=( const Integer &a ){
  // Must check for self-assign by comparing the address.
  // Otherwise, since left side is deleted, right side is also deleted for
  // self-assign.
  if( this != &a ){
    delete m_pInt;
    m_pInt = new int(*a.m_pInt);
  }

  return *this;
}
```
<br />
<br />

# Move constructor with assignment operator.
```cpp
// header
class Integer {
  Integer & operator =(const Integer &&a);
}

// source
Integer & Integer::Integer operator=( const Integer &&a ){
  if( this != &a ){
    delete m_pInt;
    *m_pInt = *a.m_pInt;
    a.m_pInt = nullptr;
  }
  return *this;
}
```

