# auto Keyword

- From C++11, the compiler will automatically infer the type from the initializer.
```cpp
auto <identifier> = <initiailzer>
```
- an intializer could be: literal, math expression or a function which returns a value.
- auto always need an intializer.
- For constant declaration, `auto` needs `const`. e.g. `const auto i = 100`;
- But for the reference, the `auto` will convert to `const`. e.g. `auto &var1 = x;` if `x` was `const`.
- You should avoid initializing `auto` with pointer or reference.
- You need assignment operator for using `auto` in the list. e.g. `auto list = {1,2,3,4};` not the uniform initializer like `auto list{1,2,3,4};`.
- If `auto` was used non-list uniform initializer, it will work. e.g.  `auto someVar{1};`

## Advantage of auto.
- They're useful in lambda expression.