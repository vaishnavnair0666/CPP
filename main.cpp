#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{1, 2, 3, 4, 3, 5};

  std::sort(v.begin(), v.end());

  v.erase(std::remove(v.begin(), v.end(), 3), v.end());
  std::cout << "after erase";
  for (const auto &x : v) {
    std::cout << x << " ";
  }

  auto it = std::find(v.begin(), v.end(), 4);
  if (it != v.end()) {
    std::cout << "\nFound " << *it << "\n";
  }

  return 0;
}
