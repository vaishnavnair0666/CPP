#include <algorithm>
#include <iostream>
#include <vector>

void print(const std::vector<int> &v) {
  for (int x : v) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

std::vector<int> reversed_manual(const std::vector<int> &v) {
  std::vector<int> result;
  result.reserve(v.size());

  for (size_t i{0}; i < v.size(); ++i) {
    result.push_back(v[v.size() - 1 - i]);
  }

  return result;
}

std::vector<int> reversed_stl(const std::vector<int> &v) {
  std::vector<int> result = v;
  std::reverse(result.begin(), result.end());
  return result;
}

int main() {
  std::vector<int> original{1, 2, 3, 4, 5};

  std::cout << "Original vector:\n";
  print(original);

  std::vector<int> r1 = reversed_manual(original);
  std::cout << "\nReversed (manual):\n";
  print(r1);

  std::vector<int> r2 = reversed_stl(original);
  std::cout << "\nReversed (STL):\n";
  print(r2);

  std::cout << "\nOriginal still unchanged:\n";
  print(original);

  return 0;
}
