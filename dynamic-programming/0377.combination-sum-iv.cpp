#include <vector>

class Solution {
public:
  int combinationSum4(std::vector<int> &nums, int target) {
    std::vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;
    for (int sum = 1; sum <= target; sum++) {
      for (int x: nums) {
        if (sum - x >= 0)
          dp[sum] += dp[sum - x];
      }
    }
    return dp[target];
  }
};
