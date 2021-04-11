# Difference between Initiailization and Assignment

```cpp
int main() {
  Integer a;
  a = 6; // Assignment
  Integer b{5}; // Initialization
}
```

## Explanations
- For Assignment, it has more cosntructor operations.
  - First it uses to default constructor for creating `a`.
  - Then it uses parameteriezed constructor for converting the number `6` to `Integer` object.
  - Then it uses overloaded assignment to move from object created from the number to `a`.
  - Then it also needs to destruct the temporary object which you used for moving constructor.
- For Initialization, it will only call parameterized constructor.

## How do you use 'initialization' for the component object in the class?
- Suppose that the class `Product` contains `Integer` as a member property.
- In parameterized constructor, if you use assignment operator, the Integer object will be copied.
- However, as explained earlier, it is always good practice to use initialization rather than assignment.
- To do initialization for parameterized constructor, you need the **member initializer lists** to achieve this.

### Example
```cpp
class Product {
  Integer m_Id;
public:
  Product(const Integer & id):m_Id(id); // notice m_Id(id) is a initialization.
}
```
Note: you can also initialize primitive type like the code above.