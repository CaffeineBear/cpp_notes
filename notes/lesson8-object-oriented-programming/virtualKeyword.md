# Virtual Functions

- Pointing to a base class reference will allow us to point to the child
  as well.
  - Why this is good? If there is a function were built in genernal
    purpose that is common between some classes, it will make sure the
    overriden functions were called.
  - This is because the compiler does not know which object it points
    during the compile time. However, using `virtual` keyword, the
    compiler now knows which methods should be invoked.
  - This is called **Polymorphism**.
- virtual pointer is a part of object


## Polymorphism
- Different forms of the function are provided.
- the call is resolved at compile time or runtime.
  - compile time poly. : function overloading, operator overloading and
    templates
  - run time poly. (aka dyanmic binding):
    - implemented through virtual mechanism
    - compiler insert code to invoke the correct function at runtime.
    - invoked via base class pointer or reference.

### Advantage of polymorphism
- The code that uses polymorphism doesn't have to know the actual object
  on which the functions are invoked.
- It only needs to know about the base.

### Virtual Mechanism
- The compiler generates an array of function pointers. This array is
  called Virtual table. This table contains addresses of virtual functions.
- A virtual pointer is stored as a member variable which points to the table of the corresp. class.
- This virtual pointer is inherited by child class and initialized to its own virutal table.
- For non-vritual functions, the compiler directly calls that function.
- For virtual functions,
  1. Get the object address
  2. Get the virtual pointer
  3. Find the position of the function in vtable
  4. Get the address of the function
  5. Invoke the funciton. (by adding offeset)

## IMPORTANT NOTE
- You need to make <span style="color:red">**destructor** </span> the class to be <span style="color:red">**virtual**</span>. Otherwise, it will not be invoked if you have declared the child class object dynamically.