# Global Overloading

- If the first operand of an overloaded operator has to be a primitive type then the operator should be overloaded as a global funciton.
  - e.g. `Integer sum = 5 + a;`. Notice that first operand here is a primitive integer type.


## Example

```cpp
// Overloading summation.
Integer operator+ (int x, Integer &y){
  Integer temp;
  temp.SetValue(x + y.GetValue());
  return temp;
}

// Overloading shift/insertion <<
std::ostream & operator<< (std::ostream & out, const Integer & a){
  out << a.GetValue();
  return out;
}

// Overloading shift/insertion >>
std::istream & operator>> (std::istream & in, const Integer & b){
  int x;
  in >> x;
  b.SetValue(x);
  return in;
}

int main() {
  Integer a(1), b(3);
  Integer sum1 = a + 5; // assuming the operator is overloaded at Integer class
  Integer sum2 = 5 + a; // using the global overloaded operator.

  std::cin >> a;
  std::cout << a << std::endl;

  return 0;
}
```