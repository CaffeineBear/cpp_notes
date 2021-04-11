# Perfect Forwarding, std::forward

- By passing R-value reference, initialization of the object will not
  create a copy but rather use move constructor.
- However, for some cases (user defined classes) has the variable name in
  the argument. This makes it the object argument to be L-value reference.
  Therefore, it will call copy construtor.
  - To resolve this you need to put `std::move` in your constructor.
  - e.g.
  - `Employee(std::string &&name, Iteger &&id): m_name{name}, m_id{std::move(id)}`
  - But not all people initialize with R-value like:
   `Employee emp1{"Umar", 100}`.
  - Some arguments might be initialized elsewhere.
  - Do we need to create all possible combination to use move constructor?
    - No. Use template.

### Example
```cpp
class Employee {
  std::string m_name;
  Integer m_id;
public:
  template<typename T1, typename T2>
  Employee(T1 && name, T2 &&id):
    m_name{name},
    m_id{id} { // But this still has issue since it will pass as id.

    }
}

int main(){
  Employee emp1{ "Umar", Integer{100} };
  return 0;
}
```
- To resolve the issue above, we need to preserve the state as L-value or
  R-value. Then we can use `std::forward`

## Solution
```cpp
class Employee {
  std::string m_name;
  Integer m_id;
public:
  template<typename T1, typename T2>
  Employee(T1 && name, T2 &&id):
    m_name{std::forward<T1>(name)},
    m_id{std::forward<T2>(id)} { // But this still has issue since it will pass as id.

    }
}

int main(){
  Employee emp1{ "Umar", Integer{100} };
  return 0;
}
```
- <span style="color:red">**IMPORTANT NOTE:**</span> Perfect forwarding only works with template type arguments.