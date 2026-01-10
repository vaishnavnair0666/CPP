#include <iostream>
void swap(int &a, int &b) {
  int temp{};
  temp = b;
  b = a;
  a = temp;
}
int main() {

  int a{}, b{};
  std::cin >> a >> b;
  swap(a, b);
  std::cout << "a:" << a << "b:" << b << "\n";
  return 0;
}
