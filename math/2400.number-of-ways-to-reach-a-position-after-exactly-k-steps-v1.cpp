#include <algorithm>
#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

public:
  int numberOfWays(int startPos, int endPos, int k) {
    long long offset = k;

    if (std::abs(endPos - startPos) > k) return 0;

    std::vector<std::vector<long long>> dp(k + 1, std::vector<long long>(2 * k + 10, 0));
    dp[0][0 + offset] = 1;

    for (int t = 1; t <= k; t++)
      for (int p = -k; p <= k; p++) {
        if (p - 1 >= -k)
          dp[t][p + offset] = (dp[t][p + offset] + dp[t - 1][p - 1 + offset]) % M;
        if (p + 1 <= k)
          dp[t][p + offset] = (dp[t][p + offset] + dp[t - 1][p + 1 + offset]) % M;
      }

    return dp[k][std::abs(endPos - startPos) + offset];
  }
};
