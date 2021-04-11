# Abstract Classes
- to provide an appropriate base class from which other classes can
  inherit.
- Abstract classes cannot be used to instantiate objects and serves only
  as an interface.
- Therefore, the member function has to be a pure virtual function.
  - `virtual void Serialize(float version) = 0;`
  - Adding `= 0` indicates it is a pure virtual specifier.
  - By adding this, we can gurantee that the child class should
    implment such function.
- Abstract class at least have one pure virtual function.
  - it can also contain other members (including non-virtual functions)
  - but it cannot be instantiated.
  - it is used for creating an interface.
- An interface will only contain the pure virtual functions.

## Pure Virtual Functions
- Usually does not have an implementaion
- but it can have implementation.
- only derived classes can invoke such functions.
- it has no entry in vtable.
- must be overriden by the derived classes.

## Further note on abstract class
- it doesnt always have to be a base class.
- it only requries at lease one pure virtual function.