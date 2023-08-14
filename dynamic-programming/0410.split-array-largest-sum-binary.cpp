#include <limits>
#include <vector>

class Solution {
public:
  int splitArray(std::vector<int> &nums, int m) {
    long left = 0, right = std::numeric_limits<int>::max();

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (checkOK(nums, m, mid))
        right = mid;
      else
        left = mid + 1;
    }

    return left;
  }

  bool checkOK(std::vector<int> &nums, int m, long val) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > val) return false;

      int j = i;
      long sum = 0;
      while (j < nums.size() && sum + (long) nums[j] <= val) {
        sum += (long) nums[j];
        j++;
      }
      count++;
      i = j - 1;
    }

    return count <= m;
  }
};
