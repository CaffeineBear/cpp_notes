# Memory Management.

- Memory Areas:
 - stack: local variables and function.
 - data: global and static data
 - heap: allocated at run time. - dynamic memory.

 ## Malloc
 - used in c.
 - should assign `null` after the `free()` function.
 - In C++, you need to explicitly change the pointer type since `malloc` returns the `void` type pointer.
 - You should always check whether `malloc` has allocated memory by checking the pointer being not `NULL`.

## New
- `new` and `delete`.
- syntax: `<type> *<variable> = new <type> (optional args); `.
- delete: `delete <variable>`;
- You should also remove any dangling pointer to point `nullptr` after it has deleted.


## Malloc vs New
| Malloc | New |
| --- | --- |
| Function | Operator |
| Requries size during allcation | Size is ascertained from the type |
| Cannot initialize memory | Can |
| Cannot call constructor | Can |
| Returns the void type so, it needs to be type casted | Correct type of pointer as LHS |
| Cannot be customized | Can be customized using operator overloading |
| Return NULL when failed | Throws an exception on failure |
- Should use New in C++.

<br/>

## New for Array.
- Syntax: `<type> *<variable> = new <type>[size];`
- For delete: `delete [] <variable>`
- char array must contain extra byte for null character.
- use `strcpy()` function for copying string to array. ( For version lower than C++11)
- use `strcpy_s(destPtr, length, srcString)` for safer version.

## Array allocation
```cpp
int main () {
  int *p1 = new int[3];
  int *p2 = new int[3];
  int **pData = new int *[2];
  pData[0] = p1;
  pData[1] = p2;
  delete[] p1; // or delete[] pData[0];
  delete[] p2; // or delete[] pData[1];
  delete pData;

}
```