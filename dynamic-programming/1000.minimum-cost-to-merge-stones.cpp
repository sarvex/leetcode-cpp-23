#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  int mergeStones(std::vector<int> &stones, int K) {
    int N = stones.size();
    if ((N - 1) % (K - 1)) return -1;

    auto dp = std::vector<std::vector<std::vector<int>>>(N, std::vector<std::vector<int>>(N, std::vector<int>(K + 1, std::numeric_limits<int>::max())));

    std::vector<int> sum(N + 1, 0);
    for (int i = 0; i < N; i++)
      sum[i + 1] = sum[i] + stones[i];

    for (int i = 0; i < N; i++) dp[i][i][1] = 0;

    for (int len = 2; len <= N; len++)
      for (int i = 0; i <= N - len; i++) {
        int j = i + len - 1;
        for (int k = 2; k <= K; k++) {
          if (k > len) continue;
          for (int m = i; m < j; m++) {
            if (dp[i][m][1] == std::numeric_limits<int>::max() || dp[m + 1][j][k - 1] == std::numeric_limits<int>::max()) continue;
            dp[i][j][k] = std::min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
          }
        }
        if (dp[i][j][K] != std::numeric_limits<int>::max())
          dp[i][j][1] = dp[i][j][K] + sum[j + 1] - sum[i];
      }

    if (dp[0][N - 1][1] == std::numeric_limits<int>::max()) return -1;
    else
      return dp[0][N - 1][1];
  }
};
