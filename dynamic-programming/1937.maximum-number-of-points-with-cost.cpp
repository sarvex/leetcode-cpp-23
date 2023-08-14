#include <algorithm>
#include <vector>

class Solution {
public:
  long long maxPoints(std::vector<std::vector<int>> &points) {
    int m = points.size();
    int n = points[0].size();

    std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, std::numeric_limits<int>::min()));
    for (int j = 0; j < n; j++)
      dp[0][j] = points[0][j];

    for (int i = 1; i < m; i++) {
      long long rollingMax = std::numeric_limits<int>::min();
      for (int j = 0; j < n; j++) {
        rollingMax = std::max(rollingMax, dp[i - 1][j] + j);
        dp[i][j] = std::max(dp[i][j], rollingMax + points[i][j] - j);
      }

      rollingMax = std::numeric_limits<int>::min();
      for (int j = n - 1; j >= 0; j--) {
        rollingMax = std::max(rollingMax, dp[i - 1][j] - j);
        dp[i][j] = std::max(dp[i][j], rollingMax + points[i][j] + j);
      }
    }

    long long ret = std::numeric_limits<int>::min();
    for (int j = 0; j < n; j++)
      ret = max(ret, dp[m - 1][j]);

    return ret;
  }
};
