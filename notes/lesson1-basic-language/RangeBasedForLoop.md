# Ranged-based for loop

- Don't need index variable.
- can be used any object with ranged behavior.
```cpp
for(variable declaration : range){
  statement;
}
```
- For example,
```cpp
int arr[] = {1,2,3};
for(int x: arr){
  // do something.
}
```
- It is better to combine with reference otherwise it will create a copy everytime running ranged base. You can also declare as const if you don't want to modify the content inside.
```cpp
int arr[] = {1,2,3};
for(int &x: arr){
  // do something.
}
```

## Advantage of Range-based for loop
- it has much cleaner syntax compared to the classic for loop approach.
- it is easier to read.
- there is no way it goes beyond the array bounce.

## Difference between For and Ranged-Based for
|For | Range-Based for|
| ------ | ------ |
| index based iteration | no need |
| requries end condition | provided by range|
| manually increment | automatic|
| error prone | less chance of error|
| more control over iteration | no control over iteration |

- So if you need more control, use `for loop`.

## More tips
- You can get the beginning and end pointer of array by `std:begin` and `std:end`.
```cpp
int *beg = std::begin(arr);
int *end = std::end(end);
```
- To use Range-based for loop, the range should give `std:begin` and `std:end` as it is internally used.
- Iterator also needs to provide operators like `!=` and `++` via operator overloading.
- Below is the sample implementation for ranged based loop
```cpp
auto &&range = arr;
auto begin = std::begin(arr);
auto end = std::end(arr);

for(;begin != end; ++begin) {
  auto v = *begin;
}
```
- From c++17, that `std:begin` and `std:end` can be a differnt type because sometimes, the type of first variable is different to end variable. For example, if you use array of char arrays, the first charcter is a char variable while end is the null character which is integer zero.
- Reference fowarding such as `&&range` is used so that you can use both lvalue and rvalue (like literal).
