# Type Conversion

- Perform through cast
- Can be done by the compiler (implicit) or by the user (explicit).
- To use it explicitly, we need casting operator.
- Conversion Types:
  1. basic and basic
  2. basic and user defined
  3. user defined and basic
  4. user defined and user defiend.

## Basic conversions
- `static_cast`
  - it does casting and it also does validation check.
- `reinterpret_cast`
  - it allows the type conversion between different types. (e.g. `char*` to `int*`)
  - similar to c style casting but any c++ qualifiers are not discarded.
- `const_cast`
  - allows you to convert from `const` to non constant type
- All casting operators above are working in comiple time.
  - C++ also has the dynamic casting.
- In general, the type casting itself should be discarded.

### Example
```cpp
int a = 5, b = 2;
float f = a/b;

std::cout<< f << std::endl; // this will print 2 because both operands are integer types.

// for correct result'
// c style cast - but discouraged in c++ because they don't perform validation check on the cast.
float f2 = (float) a/b;

// IN C++, we use static_cast
float f3 = static_cast<float>(a)/b;

```
<br/>
<br/>

## Primitive to User Type Conversion
- For example, `Integer a = 5;` this line of code relies on the compiler to use parameterized constructor defiend by user for converting type.
- If you don't want this, you can put `explicit` statement at class declaration for the parmeterized constructor. In this way, the compiler will no longer user such constructor for any type conversion.
- In most cases, you should use this `explicit` keyword unless your class is related to primitive type like `Integer` class from the lesson.

## User Type to Primitive
- You can use **Type Conversion Operator**.
- syntax: `opeartor <type>()` -> No arguments and No return type.
  - e.g. `operator <int>`

### Example
```cpp
// In header
class Integer {
  // ...some code
  operator int();
}

// In source code
Integer::operator int(){
  return *m_pInt;
}

// In main
int main() {
  Integer a1{5};

  // compiler will implicitly changes its type using type conversion operator.
  int x = a1;

  // However for reader, this is confusing. So you can add 'explicit'
  // keyword to enforce to use static_cast.
  int x2 = static_cast<int>(a1);
}
```