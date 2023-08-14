#include <algorithm>
#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int> &nums) {
    int left = 0;
    int right = 0;

    while (right < nums.size()) {
      if (nums[right] == 0) {
        right++;
      } else {
        std::swap(nums[left], nums[right]);
        left++;
        right++;
      }
    }
  }
};
