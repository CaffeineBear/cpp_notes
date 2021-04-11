# Function Overloading

- You must have different type/number of arguments in order to use them.
- Qualifiers such as `cosnt` or `&` also triggers function overloading.
- Return type is ignored.
- The function overloading is resolved at the compile-time. aka static polymorphism.
- convinent for the caller.

## How does compiler manages unique functions?
- The compiler uses the process called 'Name Mangling' to produce the unique name for the compiler.
- This allows the linker to properly link to the correct overloaded function.

## Extern C
- Name Mangling is not used by other languages, so `extern "C"` will remove the unique name.
- You need to use `extern "C"` in both header and implementation file.
- If you have header file declared on the top of the implementation file, you don't need to use `extern "C"` declaration.
