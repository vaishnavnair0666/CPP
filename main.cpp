#include <algorithm>
#include <iostream>
#include <vector>

int longestSubarray(const std::vector<int> &nums, int K) {
  int left = 0;
  int sum = 0;
  int maxLen = 0;
  int s = nums.size();
  for (int right = 0; right < s; ++right) {
    sum += nums[right];

    while (sum > K) {
      sum -= nums[left];
      ++left;
    }

    maxLen = std::max(maxLen, 1 + right - left);
  }

  return maxLen;
}

int main() {
  std::vector<int> v{13, 2, 5, 7, 3, 4, 2, 1, 1};
  int k{13};
  std::cout << longestSubarray(v, k) << "\n";
}
