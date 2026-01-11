#include <algorithm>
#include <iostream>
#include <vector>

bool isPossible(const std::vector<int> &piles, int h, int k) {
  int hours = 0;
  for (int bananas : piles) {
    hours += (bananas + k - 1) / k;
  }
  return hours <= h;
}

int minEatingSpeed(const std::vector<int> &piles, int h) {
  int left = 1;
  int right = *std::max_element(piles.begin(), piles.end());
  int ans = right;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (isPossible(piles, h, mid)) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return ans;
}

int main() {
  std::vector<int> v{12, 2, 31, 4, 22, 7, 8};
  int hours{};
  std::cin >> hours;
  std::cout << minEatingSpeed(v, hours) << "\n";
  return 0;
}
