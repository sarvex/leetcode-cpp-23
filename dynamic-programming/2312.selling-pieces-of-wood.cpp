#include <algorithm>
#include <std::vector>

class Solution {
  long long dp[201][201];

public:
  long long sellingWood(int m, int n, std::vector<std::vector<int>> &prices) {
    for (auto x: prices)
      dp[x[0]][x[1]] = x[2];

    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        for (int k = 1; k < i; k++)
          dp[i][j] = std::max(dp[i][j], dp[k][j] + dp[i - k][j]);

        for (int k = 1; k < j; k++)
          dp[i][j] = std::max(dp[i][j], dp[i][k] + dp[i][j - k]);
      }

    return dp[m][n];
  }
};
