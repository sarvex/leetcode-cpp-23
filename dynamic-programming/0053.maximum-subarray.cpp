#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<int> dp(n);
    dp[0] = nums[0];
    int ret = nums[0];

    for (int i = 1; i < n; i++) {
      dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
      ret = std::max(dp[i], ret);
    }

    return ret;
  }
};
