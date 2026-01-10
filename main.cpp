#include <iostream>
#include <utility>

void print(const int *arr, size_t size) {
  for (size_t i{0}; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
}

void rev(const int *arr, size_t size, int *b) {
  for (size_t i{0}; i < size; ++i) {
    b[i] = arr[size - 1 - i];
  }
}

void revswap(int *arr, size_t size) {
  for (size_t i{0}; i < size / 2; ++i) {
    std::swap(arr[i], arr[size - 1 - i]);
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
