#include <iostream>
#include <memory>

class Project {
private:
public:
  std::shared_ptr<Employee> m_emp;
  Project() {
    std::cout << "Employee()" << std::endl;
  }
  ~Project() {
    std::cout << "~Employee()" << std::endl;
  }
};

class Employee {
private:
public:
  std::weak_ptr<Project> m_prj;
  Employee() {
    std::cout << "Employee()" << std::endl;
  }
  ~Employee() {
    std::cout << "~Employee()" << std::endl;
  }
};



int main() {
  std::shared_ptr<Employee> emp{new Employee{}};
  std::shared_ptr<Project> prj{new Project{}};

  // Trying to have circular refrence.
  emp->m_prj = prj;
  prj->m_emp = emp;
  return 0;
}