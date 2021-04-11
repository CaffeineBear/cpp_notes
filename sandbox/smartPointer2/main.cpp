#include <iostream>
#include <memory>

class Project {
public:
  ~Project(){
    std::cout << "~Project()" << std::endl;
  }
};

class Employee {
  std::shared_ptr<Project> m_pProject;
  std::string name;
public:
  Employee(std::string name){
    this->name = name;
  }
  void SetProject(std::shared_ptr<Project> p){
    m_pProject = p;
  }
  Project * GetProject() const {
    return m_pProject.get();
  }
  ~Employee(){
    std::cout << "~Employee(): " << name << std::endl;
  }
};

std::shared_ptr<Employee> AssignProject() {
  std::shared_ptr<Project> p{new Project{}};
  Employee *e1 = new Employee{"New User"};
  e1->SetProject(p);
  return std::shared_ptr<Employee>{e1};
}

int main() {
  using namespace std;
  cout << "Assign new project" << endl;
  auto assignedEmployee = AssignProject();

  cout << "Replace Employee" << endl;
  assignedEmployee.reset(new Employee{"Martin"});

  cout << "Terminates here" << endl;
  return 0;
}