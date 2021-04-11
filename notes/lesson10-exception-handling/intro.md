# Error Handling

- it exists outside the normal functioning of the program.
- it requires immediate handling by the program
- otherwise, it will crash
- In C, it returns error code from the function rather than exception.

## implementations tips
- catch block should contain the reference so that it will not create a copy.
- Do not use exception to validate user input.

## Useful exception class
- `std::runtime_error`
- `std::out_of_range`
- `std::bad_alloc`
- `std::exception` - catches all of exception.
  - You can also use `...` but it will not record anything.
    - should be avoided as possible

## Stack Unwinding
- When the function throws an exception, then the destructor will be
  called before catching exception.
- Also any local objects are destroyed.
- Note: object on heap will not be destroyed.
  - So it is important to use smart pointer instead.
  - or use containers

## Nested Exception
- For the nested one to throw exception to outer scope, it needs to throw
  from the catch pharse.
  - with empty `throw;`, it will pass the exception object as well.
  - If you want to modify, you need to modify original inner exception
    object.
    (You need to also make exception as a reference to make this work.)

## Exception in constructor and destructor.
- we need to deal with the heap memory instantiated at constructor in case
  that the constructor throws error.
  - To resolve this, we need smart pointer and containers.
- What about the exception in destructor? How do we handle them?
  - it should be handled within the destructor itself. Otherwise, it will
    crash.

## noexcept keyword.

- To indicate that function does not throw exceptions.
  - then the compiler can optimize more because it will not generate stack
    unwinding code.
- An exception from such function terminates the program. (stack may or
  may not be unwinded)
- Not all function should use noexcept specifier
  - especially functions calling other functions (e.g. library)
- `noexcept` could accept booliean. (inidicating whether this is noexcept
  or not)
- The default exception specification is noexcept(false).
- `noexcept` also can specify the sub function it calls whether they are
  noexcept or not.
  - e.g.`int Sum(int x, int y) noexcept(noexcept(Test(x))) {/*somecode*/};`
- In C++11, all destructors has `noexcept` by default.
- For the containers to use move operations, it is important that you use
  `noexcept(true)` on your function.

### IMPORTANT NOTE
- When the constructor throws an exception, the destructor is not invoked.

