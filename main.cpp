#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  std::vector<int> nums{2, 2, 2, 2, 11, 7, 15};
  int target = 9;
  std::unordered_map<int, int> seen;

  for (size_t i = 0; i < nums.size(); ++i) {
    int needed = target - nums[i];

    if (seen.count(needed)) {
      std::cout << "Found pair at indices: " << seen[needed] << " and " << i
                << "\n";
      std::cout << "Values: " << needed << " + " << nums[i] << " = " << target
                << "\n";
      return 0;
    }

    seen[nums[i]] = i;
  }

  std::cout << "No pair found\n";
  return 0;
}
