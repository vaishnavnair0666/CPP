#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

int maxSubarraySum(const std::vector<int> &nums, size_t k) {
  int windowSum = 0;
  int maxSum = 0;

  for (size_t i = 0; i < nums.size(); ++i) {
    windowSum += nums[i];

    if (i >= k - 1) {
      maxSum = std::max(maxSum, windowSum);
      windowSum -= nums[i - (k - 1)];
    }
  }

  return maxSum;
}

int main() {
  std::vector<int> v{1, 2, 5, 7, 3, 4, 2, 1, 1};
  size_t k{3};
  std::cout << maxSubarraySum(v, k) << "\n";
}
