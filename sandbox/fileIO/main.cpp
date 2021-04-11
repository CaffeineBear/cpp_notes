#include <iostream>
#include <fstream>

void Write() {
  std::ofstream out{"data.txt"};
  out << "Hello" << std::endl;
  out << 10 << std::endl;
  out.close();
}

void Read() {
  std::ifstream input;
  input.open("data.txt");
  std::string message;
  std::getline(input, message);
  int value{};
  input >> value;
  input.close();
  std::cout << message << ":" << value << std::endl;
}

int main() {
  Write();
  Read();
  return 0;
}