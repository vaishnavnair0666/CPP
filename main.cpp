#include <iostream>
int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}
int main() {

  int a{}, b{};
  std::cin >> a >> b;
  std::cout << max(a, b) << "\n";
  return 0;
}
