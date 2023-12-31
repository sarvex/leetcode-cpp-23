#include <numeric>
#include <vector>

class Solution {
  long long dp[1005][1005];
  static const long long M = 1e9 + 7;

public:
  int countPartitions(std::vector<int> &nums, int k) {
    if (std::accumulate(nums.begin(), nums.end(), 0LL) < k * 2)
      return 0;

    int n = nums.size();
    nums.insert(nums.begin(), 0);

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
      for (int s = 0; s < k; s++) {
        dp[i][s] += dp[i - 1][s];
        if (s >= nums[i])
          dp[i][s] += dp[i - 1][s - nums[i]];
        dp[i][s] %= M;
      }

    long long total = 1;
    for (int i = 1; i <= n; i++)
      total = total * 2 % M;

    long long invalid = 0;
    for (int s = 0; s < k; s++)
      invalid = (invalid + dp[n][s]) % M;

    return (total - invalid - invalid + M) % M;
  }
};
