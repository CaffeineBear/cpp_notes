# Rules for overloading

- Associativity, precedence and arity('operator count') does not change.
- should be non static
  - except for `new` and `delete` ( they are overloaded only on special circumstances )
- one argument should be user-defined type when there are more than one arguments. Otherwise, the compilation fails.
- if the first operand is the primitive type, you need to have global overloading.
- Some operators cannot be overloaded: `. ?: .* sizeof` -> member access, tenary, pointer to member and size of and etc.
- You can't not define new operators.


