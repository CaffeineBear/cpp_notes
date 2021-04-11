# Type traits
- In computing, type **introspection** is the ability of a program to
  examine the type or properties of an object at runtime.
- In C++, type traits give the ability to introspect.
  - characteristic of types at compile time.
  - transform the properties of the type.
- Very useful in template metaprogramming.
  - very efficient code as it is created by the compiler.
- Type traits will either return booliean or a type.
- `<type_traits>` are defined in header and provides template-based
  interface.
- Note some compiler does not support some type traits.

## Example
```
is_void
is_null_pointer
is_array
```