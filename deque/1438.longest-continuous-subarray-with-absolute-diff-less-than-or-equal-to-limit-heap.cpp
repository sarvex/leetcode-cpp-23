#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
  int longestSubarray(std::vector<int> &nums, int limit) {
    std::multiset<int> Set({nums[0]});
    int j = 0;
    int ret = 0;

    for (int i = 0; i < nums.size(); i++) {
      while (*Set.rbegin() - *Set.begin() <= limit) {
        ret = std::max(ret, j - i + 1);
        j++;
        if (j >= nums.size()) break;
        Set.insert(nums[j]);
      }

      if (j >= nums.size()) break;

      Set.erase(Set.find(nums[i]));
    }

    return ret;
  }
};
