#include <iostream>
void print(const int *arr, int size) {
  for (int i{0}; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
}
void revswap(int *arr, int size) {
  for (int i{0}; i < size / 2; ++i) {
    arr[i] = arr[i] + arr[size - 1 - i];
    arr[size - 1 - i] = arr[i] - arr[size - 1 - i];
    arr[i] = arr[i] - arr[size - 1 - i];
  }
}
void rev(const int *arr, int size, int *b) {
  for (int i{size - 1}; i > -1; --i) {
    b[i] = arr[size - 1 - i];
  }
}
int main() {

  int a[4] = {1, 2, 3, 4};
  int b[4];
  std::cout << "arr a = ";
  print(a, 4);
  std::cout << "\narr b which is rev a = ";
  rev(a, 4, b);
  print(b, 4);
  revswap(a, 4);
  std::cout << "\narr a which is rev w/o b = ";
  print(a, 4);
  std::cout << "\n";
  return 0;
}
