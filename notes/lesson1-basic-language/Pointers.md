# Address of Operator
- & is the address of operator.
- when we apply to variable, we get the address of that variable.
- `void` ptr can point to any kind of variable.

# Dereference pointer
- it allows indirect read or write on the variable
```cpp
int x = 10;
int *ptr = &x;
*ptr = 5;
int y = *ptr;
// now the value of y is 5.
```

# NULL pointer
- `NULL` is a macro in C & pre-C++11
- it is defined as 0 in most compiler.
- For C++11 and above, it has `nullptr`.
- Since `nullptr` is type safe, it is better than `NULL`.
- Note that you cannot read from the `nullptr`. If you attempt to read it, the program might crash
- Also you can't write anything to `nullptr`.