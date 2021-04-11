# Argument Deduction and Instantiation in Template

- Deducing types
- The compiler examines each argument and corresp. type is deduced.
- Note that no type conversions are executed.
- After the deduction, the template is instantiated.
- We can override the deduction by manually specifying the types.
  - e.g. `Max<int>(3,5);`


## Template Instantiation
- Occurs implicitly when:
  - a function template is invoked
  - taking address of a function template
    - e.g. `int (*pfn)(int, int) = Max;`
  - using explicit instantiation
    - e.g. ` template char Max(char x, char y); `
    - You can use explicit instantiation to create an instantiation of a templated class or function without actually using it in your code. Because this is useful when you are creating library (.lib) files that use templates for distribution, uninstantiated template definitions are not put into object (.obj) files.
  - creating explicit specialization.
    - e.g. `Max<double>(3,5);` -> they are now interpret as 3.0 and 5.0
- Since whole definitions of template should be available, they're written
  in header file.
- An explicit instantiation definition forces instantiation of the class, struct, or union they refer to. It may appear in the program anywhere after the template definition, and for a given argument-list, is only allowed to appear once in the entire program, no diagnostic required.