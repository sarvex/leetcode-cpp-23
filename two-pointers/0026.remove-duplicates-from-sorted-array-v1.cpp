#include <algorithm>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    int i = 0;
    int j = 1;

    while (j < nums.size()) {
      if (nums[j] == nums[j - 1]) {
        j++;
      } else {
        i++;
        std::swap(nums[i], nums[j]);
        j++;
      }
    }
    return i + 1;
  }
};
