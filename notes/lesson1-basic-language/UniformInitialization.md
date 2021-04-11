# Uniform Initialization

From C++98
- You either initialize variable with 'Scalar' or 'Array' types. (C++98)
- Scalar with `()`
- Array with `{}`

From C++11
- Use `{}` to initialize everything.

Why do we use this?
- we have uniform syntax to initialize all types.
- forces initialization so that you don't get junk value.


# Types of initialization WITHOUT uniform initialization.
```cpp
int a2 = 0; // copy
int a3(5); // direct
std::string s2("some string"); // direct


// for char array you can initialize with null character or aggregate values
char d2[8] = {'\0'};
char d3[8] = {'a', 'a', 'a', 'a', 'a'}; // aggregate
char d3[8] = {"abcd"}; // aggregate
```

# Types of initialization WITH uniform initialization
```cpp
int b1{}; // Value initialization
int b2(); // Most vexing parse - used for function.
int b3{5}; // Direct initialization

char e1[8]{};
char e1[8]{"Hello"};

// Heap
int *p = new int{};
char *p2 = new char[8]{};
char *p3 = new char[8]{"Hello"};
```

Summarizing above:
1. Value initialization => T obj{};
1. Direct initialization => T obj{value};
1. Copy initialization => T obj = value;

# Should you use uniform initialization everywhere?
- no. For primitive types, you can stick to assignment. But, for user defined types,
you should always use uniform initialization because you can force others to use
initialize values. It also prevents narrowing conversion. It also has the uniform
syntax for all types.

# What is narrowing conversion.
- A narrowing conversion changes a value to a data type that might not be able to hold some of the possible values. For example, a fractional value is rounded when it is converted to an integral type, and a numeric type being converted to Boolean is reduced to either True or False .

