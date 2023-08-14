#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> largestDivisibleSubset(std::vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n == 0) return {};
    std::vector<int> dp(n, 1);
    std::vector<int> prev(n, -1);

    for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
          dp[i] = std::max(dp[i], dp[j] + 1);
          if (dp[i] == dp[j] + 1)
            prev[i] = j;
        }
      }

    int len = 0, idx;
    for (int i = 0; i < n; i++) {
      if (dp[i] > len) {
        len = dp[i];
        idx = i;
      }
    }

    std::vector<int> ret;
    while (idx != -1) {
      ret.push_back(nums[idx]);
      idx = prev[idx];
    }
    return ret;
  }
};
