# Delegating Constructor
- useful when you have multiple constructor in the class.
- helps you avoid duplication of the code.

## Example
-  in the following code, the `Car(float amount, int pass)` will be executed as a result.
```cpp
// Car.cpp
Car::Car():Car(0) {
  cout << "Car()" << endl;
}

Car::Car(float amount): Car(amount, 0) {
  cout << "Car(float)" << endl;
}

Car::Car(float amount, int pass) {
  cout << "Car(float, int)" << endl;
  ++totalCount;
  fuel = amount;
  speed = 0;
  passengers = 0;
}
```
- The code above will print:
```
Car(float, int)
Car(float)
Car()
```