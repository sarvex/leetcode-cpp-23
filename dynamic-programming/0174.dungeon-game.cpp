#include <algorithm>
#include <vector>

class Solution {
public:
  int calculateMinimumHP(std::vector<std::vector<int>> &dungeon) {
    int M = dungeon.size();
    int N = dungeon[0].size();
    auto dp = std::vector<std::vector<int>>(M, std::vector<int>(N, 1));

    for (int i = M - 1; i >= 0; i--)
      for (int j = N - 1; j >= 0; j--) {
        if (i == M - 1 && j == N - 1)
          dp[M - 1][N - 1] = 1;
        else if (i == M - 1)
          dp[i][j] = dp[i][j + 1] - dungeon[i][j + 1];
        else if (j == N - 1)
          dp[i][j] = dp[i + 1][j] - dungeon[i + 1][j];
        else
          dp[i][j] = std::min(dp[i][j + 1] - dungeon[i][j + 1], dp[i + 1][j] - dungeon[i + 1][j]);

        dp[i][j] = std::max(dp[i][j], 1);
      }

    dp[0][0] = dp[0][0] - dungeon[0][0];
    dp[0][0] = std::max(dp[0][0], 1);

    return dp[0][0];
  }
};
