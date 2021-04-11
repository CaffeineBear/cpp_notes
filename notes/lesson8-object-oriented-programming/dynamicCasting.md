# Dynamic Casting

- Similar to `type_id` it also checks type and if the type does not match
  it will return `nullptr`.
- `Checking *pChecking = dynamic_cast<Checking*>(pAccount);`
- Note that this also works for class reference.
  - For this case, it will throw an exception when it can not cast.
  - However, we should avoid using this.
  - The reason is that the compiler has to add extra information to the
    polymorphic classes. (Slower than `type_id`)