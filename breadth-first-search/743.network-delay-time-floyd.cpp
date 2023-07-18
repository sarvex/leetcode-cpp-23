#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

class Solution
{
public:
  int networkDelayTime(std::vector<std::vector<int>> &times, int N, int K)
  {

    auto dp = std::vector<std::vector<int>>(N + 1, std::vector<int>(N + 1, std::numeric_limits<int>::max() / 2));

    for (auto &t : times)
      dp[t[0]][t[1]] = t[2];
    for (int i = 1; i <= N; i++)
      dp[i][i] = 0;

    for (int k = 1; k <= N; k++)
      for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
          dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);

    int ret = 0;
    for (int i = 1; i <= N; i++)
      ret = std::max(ret, dp[K][i]);

    return (ret == std::numeric_limits<int>::max() / 2) ? -1 : ret;
  }
};
