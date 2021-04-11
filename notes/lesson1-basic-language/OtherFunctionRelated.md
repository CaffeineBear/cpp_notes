# Default Arguments

- Default arguments should begin from the right side in the list of function arguments.

# Inline Functions
- The inline keyword will work similar as C's macro functions.
- It will not create the memory in stack. Meaning there are no overheads.
- the argument is first evaluated unlike C macro functions. (better than C)
- The `inline` keyword will replace the call with the function body. Therefore, it doesn't use stack memory for arguments and returning address.
- Note: IT IS ONLY A REQUEST TO THE COMPILER. It will not always be inlined.
- some functions can not be inlined:
  - large functions
  - functions with many conditional statements
  - recursive functions
  - functions which are invoked with the pointers.
  - etc.
- modern compiler will auto inline some code for those non-inline functions.
- excessive inlining will increase the size of binary file.

## Macros vs Inline
| Macros | Inline |
| ------ | ------ |
| work through text subs. | the call is replaced with body |
| Error prone because of text subs. | Less error as it is same as other function semantics |
| Difficult for multiline code | Easier |
| Can not be used for member function | member function can be inlined |

<br />

# Function Poitners
- contains the address of the function
- can indirectly invoke function without function name known.
- Used by algorithms and classes for customization.
- For example,
```cpp
void Print(int count, char ch) {
  using namespace std;
  for (int i = 0; i < count ; ++i){
    cout << ch;
  }
  cout << endl;
}
int main() {
  void (*ptr) (int, char) = &Print; // or Print will also work since the name of the function itself is the address.

  // There are two ways
  (*ptr)(8, '*');
  ptr(8, '#');
  return 0;
}
```
- `atexit()` will be invoked just before the program terminates.