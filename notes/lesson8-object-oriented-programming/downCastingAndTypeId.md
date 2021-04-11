# Downcasting and typeid

- If you have a base class pointer while you want to access child
  function, you need **Downcasting**.
- The other way around is call **Upcasting**
- When you do downcasting, it is important to check whether it is pointing
  to the correct child or not.(Because if some other class has the same
  base class, it might not have the same member as the child class you
  want to refer to)
- To resolve this issue, you should use `typeid` in `<typeinfo>`
  - e.g. `const std::type_info &ti = typeid(i);`
  - it has the equality operator,
  - it has the function called name. And this is human readable.
  - To know where the class pointer is pointing at:
    - `const std::type_info &ti = typeid(*p);`
    - where `*p` is the dereferencing the pointer to Account which points
      to the saving.
  - The `type_id` in non-polymorphic ones then it collects the type info
    at the compile time.
  - For the polymorphic-types, like we used on `Account` pointer, it will
    work at running time.
  - So use it only for polymorphic type.

## Example
```cpp
Savings ch{"Bob", 100, 0.05f};
Account *p = &ch;
const std::type_info &ti = typeid(*p);
if(ti == typeid(Savings)){
  // do some operations
}
```

## IMPORTANT NOTE
- The type information is added to the class only when there is a virtual function because otherwise, it is a non-polymorphic type.