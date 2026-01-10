#include <algorithm>
#include <iostream>
#include <vector>

void print(const std::vector<int> &v) {
  for (int x : v) {
    std::cout << x << " ";
  }
  std::cout << "\n";
}

void reverse_manual(std::vector<int> &v) {
  size_t n = v.size();
  for (size_t i = 0; i < n / 2; ++i) {
    std::swap(v[i], v[n - 1 - i]);
  }
}

std::vector<int> reversed(const std::vector<int> &v) {
  std::vector<int> result;
  result.reserve(v.size());

  for (size_t i{0}; i < v.size(); ++i) {
    result.push_back(v[v.size() - 1 - i]);
  }

  return result;
}
void reverse_stl(std::vector<int> &v) { std::reverse(v.begin(), v.end()); }

int max_element(const std::vector<int> &v) {
  int max = v[0];
  for (size_t i = 1; i < v.size(); ++i) {
    if (v[i] > max) {
      max = v[i];
    }
  }
  return max;
}

int main() {
  int n;
  std::cout << "Enter number of elements: ";
  std::cin >> n;

  std::vector<int> v;
  v.reserve(n);

  std::cout << "Enter elements:\n";
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    v.push_back(x);
  }

  std::cout << "\nOriginal vector:\n";
  print(v);

  std::cout << "\nMax element: ";
  std::cout << max_element(v) << "\n";
  std::vector<int> r = reversed(v);
  // reverse_manual(v);
  std::cout << "\nAfter manual reverse:\n";
  print(v);

  reverse_stl(v);
  std::cout << "\nAfter STL reverse:\n";
  print(v);

  return 0;
}
