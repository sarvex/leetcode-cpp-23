#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int destroyTargets(std::vector<int> &nums, int space) {
    int len = 0;
    int ret = 0;

    std::sort(nums.rbegin(), nums.rend());

    std::unordered_map<int, int> dp;

    for (int i = 0; i < nums.size(); i++) {
      int r = nums[i] % space;
      dp[r] = dp[r] + 1;

      if (dp[r] > len) {
        ret = nums[i];
        len = dp[r];
      } else if (dp[r] == len) {
        ret = nums[i];
      }
    }

    return ret;
  }
};
