# Core concept for OOP.

## Abstraction
- To focus on important and necessary details
- Allow us to represent real-life obj but without complexity.

## Encapsulation
- Hides the implementaion details of a class.

## Inheritance
-  Represents a hierarchy of classes.
- Behaviour and its implementation is inherited by children.
- Promotes reuse & extensibility.
- "is-a" relationship.
- e.g. Dog is an animal.

## Composition
- Relationship between objects.
- "has-a" or "part-of" relationship.
- e.g. Car has an engine.

## Polymorphism
- Common behaviour with different implementations.
- e.g. car, person, cycle can move differently. They are all 'moving' but with different ways.
- In programming => function overloading, templates, virtual functions.
- Used conjunction with inheritance & composition.

<br />

# Structure
- by default the access is public unlike class.
- In C++, the structure is often used for the abstract data type. (e.g. records -> public access to member)
- Also used for function objects.
```cpp
struct Point {
  int x;
  int y;
}
void DrawLine(Point start, Point end);
```


# 'This' operator.
- useful for returning object itself.
```cpp
void Foo(const Car &car){

}
void Car::AddPassenger(int passengers){
  Foo(*this);
}
```

<br />

# Const member function
- All the member functions that do not modify the state of the object should be qualified with `const` keyword.
- Both definition and declaration should be qualified.
- This function type should not change any member propterties.
- Useful for read-only methods.
- `const` objects can only call constant member function.
- Syntax:

In Car.h
```cpp
class Car {
public:
  Dashboard() const;
}
```
In Car.cpp,
```cpp
void Car::Dashboard() const {

}
```

# Static Member Variables
- Belong to class not object
- only one copy exists.
- shared between all objects.
- have to defined outside the class for initialization.

```cpp
// Car.h
class Car {
  static int totalCars;
}

// Car.cpp
int Car::totalCars; // Default to zero.

```

# Static Member Function
- Requried only in declaration.
- Belong to class not object
- Can be invoked through the classname.
- Cannot access non-static members of the class (can access only static member of the class)
- Because it can not receive the pointer to object.
<br />
<br />

# Copy constructor
- Copying the object by copying the member of one object to the other.
- Compiler will provide one if the user did not specify one.
- Default: just copy values.
- If the object contains the pointer, this default option is not desirable because it only copies the address of the pointer, not the content itself.(Shallow copy)


## User-defined copy constructor
- Syntax: `<Classname>( <ClassName> &objt);`
```cpp
// Integer.h
class Integer {
  int *m_pInt;
public:
  Integer(const Integer &obj);
  const int GetValue();
}

// Integer.cpp
Integer::Integer(const Integer &obj){
  m_pInt = new int(obj.GetValue());
}

int Integer::Integer() const {
  return *m_pInt;
}
```