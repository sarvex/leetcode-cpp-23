#include <limits>
#include <vector>

class Solution {
public:
  int getMoneyAmount(int n) {
    std::vector<std::vector<int>> dp(n + 2, std::vector<int>(n + 2, 0));

    for (int len = 2; len <= n; len++)
      for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1;
        dp[i][j] = std::numeric_limits<int>::max() / 2;

        for (int k = i; k <= j; k++)
          dp[i][j] = std::min(dp[i][j], k + std::max(dp[i][k - 1], dp[k + 1][j]));
      }
    return dp[1][n];
  }
};
