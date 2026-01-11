#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

int main() {
  std::vector<int> nums{2, 4, 1, 3};
  std::vector<int> prefix(nums.size() + 1, 0);

  for (size_t i = 0; i < nums.size(); ++i) {
    prefix[i + 1] = prefix[i] + nums[i];
    std::cout << prefix[i + 1] << "\n";
  }
  int a{}, b{};
  std::cin >> a >> b;
  std::cout << prefix[a] - prefix[b] << "\n";
  return 0;
}
