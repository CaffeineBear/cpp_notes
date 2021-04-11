# Unions for C++
- Note: this is not union for C but C++.
- To represent all the members in the same memory.
- You can save spaces. (Good for embedded system)


## Disadvantage
- There is no way to know which type it holds.
- nested types with non-default contructor deletes the default constructor
  of the union.
- Before C++11 -> illegal to use union in constructor.
- cannot assign objects of user-defined types directly to a union member.
- user-defined types are not destroyed implicitly.
- cannot have a base class.
- cannot contain a virtual function
- size of storage is determined by the largest member of the union.

## Further notes
- If the component has a class or struct, their constructor will not be
  called so you need to create a constructor manually.
- Similar for the destructor, you need to create manually.
- Note: the assignment operator can only be used if there is an instance
  created already.
- You can't assign a string to union directly.
- To inialize union, the only way is to use placement new operator.


## Example
```cpp
union UDT {
  A a;
  B b;
  UDT(){

  }
  ~UDT(){

  }
};

int main() {
  UDT udt;
  // The code below will not work as UDT will never initialze A and B
  // since they're structs.
  // udt.a = A{};

  new(&udt.s) std::string{"Hello World"};
  new(&udt.a) A{};

  // You have to manually invoke the destructor of those object.
  udt.a.~A();

}