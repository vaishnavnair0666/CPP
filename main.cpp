#include <iostream>

int main() {

  int a{}, b{}, c{};
  std::cin >> a >> b >> c;
  if (a > b) {
    if (a > c) {
      std::cout << "a is largest\n";
    }
  } else if (b > c) {
    std::cout << "b is largest\n";
  } else {
    std::cout << "c is largest\n";
  }
  return 0;
}
