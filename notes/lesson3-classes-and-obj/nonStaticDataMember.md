# Non Static Data Member

- In C++11, you can define initializer in the class definition. aka **Non-Static Data Member initializer**.
- This ensures that members are initialized.
- Compiler automatically inserts initializer in the constructor.
- User-defined constructor takes precedence. (Meaning user-defined constructor overwrites the initializer in the declarartion).
- Use Non-Static Data Member initialization for simple initialization.