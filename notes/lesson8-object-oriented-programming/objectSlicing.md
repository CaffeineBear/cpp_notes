# Object Slicing
- The compiler deliberately removes some part of an object.
- This occurs when child class object is assigned to a concrete base class object.
- Since a child object might be larger than the base class, some of the memory is overwritten.
- This causes for memory to corrupt.
  -  So the compiler does "object slicing" to avoid such situation.
- Therefore, you need to make sure that if you create a base class object
  and you want to invoke the child class member functions, through that
  object, ensure that is a **pointer or a reference**.

## Example
```cpp
Account a;
Savings s;
a = s;
```