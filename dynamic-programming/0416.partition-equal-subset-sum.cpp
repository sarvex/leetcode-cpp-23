#include <numeric>
#include <vector>

class Solution {
public:
  bool canPartition(std::vector<int> &nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    std::vector<bool> dp(sum / 2 + 1, 0);
    dp[0] = true;

    for (auto x: nums) {
      for (int s = sum / 2; s >= 1; s--) {
        if (s - x >= 0 && dp[s - x] == true)
          dp[s] = true;
      }
    }
    return dp[sum / 2];
  }
};
