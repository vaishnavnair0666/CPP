#include <cstddef>
#include <iostream>
#include <string>

void print(const std::string &s) {
  for (std::size_t i{0}; i < s.size(); ++i) {
    std::cout << s.at(s.size() - 1 - i) << " ";
  }
  std::cout << "\n";
}

int main() {
  std::string s;

  std::cout << "Enter a line: ";
  std::getline(std::cin, s);

  std::cout << "You entered: " << s << "\n";
  std::cout << "Length: " << s.size() << "\n";

  s += "!";
  print(s);

  return 0;
}
