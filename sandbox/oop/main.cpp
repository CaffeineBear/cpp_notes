#include <iostream>

class Animal {
private:

public:
  void Eat(){
    std::cout << "Animal Eating" << std::endl;
  }
  void Run(){
    std::cout << "Animal Running" << std::endl;
  }
  void Speak(){
    std::cout << "Animal speaking" << std::endl;
  }
};

class Dog : public Animal {

};



int main() {
  Dog d;
  d.Eat();
  d.Run();
  d.Speak();
  return 0;
}