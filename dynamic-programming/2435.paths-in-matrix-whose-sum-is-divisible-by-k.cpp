#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

public:
  int numberOfPaths(std::vector<std::vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<std::vector<long long>>> dp(m, std::vector<std::vector<long long>>(n, std::vector<long long>(k)));

    long long sum = 0;
    for (int i = 0; i < m; i++) {
      sum += grid[i][0];
      sum %= k;
      dp[i][0][sum] = 1;
    }

    sum = 0;
    for (int j = 0; j < n; j++) {
      sum += grid[0][j];
      sum %= k;
      dp[0][j][sum] = 1;
    }

    for (int i = 1; i < m; i++)
      for (int j = 1; j < n; j++)
        for (int t = 0; t < k; t++) {
          long long r = ((t - grid[i][j]) % k + k) % k;
          dp[i][j][t] = dp[i - 1][j][r] + dp[i][j - 1][r];
          dp[i][j][t] %= M;
        }

    return dp[m - 1][n - 1][0];
  }
};
