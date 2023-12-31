#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    if (nums.size() == 0) return 0;

    int i = 0;
    for (size_t j = 0; j < nums.size(); j++) {
      if (j == 0)
        continue;
      else if (nums[j] == nums[i])
        continue;
      else {
        i++;
        nums[i] = nums[j];
      }
    }

    return i + 1;
  }
};
