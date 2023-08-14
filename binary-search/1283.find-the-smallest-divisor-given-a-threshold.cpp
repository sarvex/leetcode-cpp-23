#include <vector>
class Solution {
public:
  int smallestDivisor(std::vector<int> &nums, int threshold) {
    int left = 1, right = std::numeric_limits<int>::max();
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (isOK(mid, nums, threshold))
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }

  bool isOK(int x, std::vector<int> &nums, int threshold) {
    int sum = 0;
    for (auto a: nums) {
      if (a % x == 0)
        sum += a / x;
      else
        sum += a / x + 1;
    }
    return sum <= threshold;
  }
};
