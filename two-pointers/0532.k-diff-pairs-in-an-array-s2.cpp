#include <algorithm>
#include <vector>

class Solution {
public:
  int findPairs(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());

    size_t i = 0;
    size_t j = 0;
    int count = 0;

    while (j < nums.size()) {
      if (nums[i] + k == nums[j] && i < j) {
        count++;
        while (nums[i] == nums[i + 1])
          i++;
        i++;
      } else if (nums[i] + k >= nums[j])
        j++;
      else
        i++;
    }
    return count;
  }
};
