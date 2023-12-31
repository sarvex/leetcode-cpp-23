#include <algorithm>
#include <limits>
#include <vector>

class Solution
{
  int dist[10][10];

public:
  int assignBikes(std::vector<std::vector<int>> &workers, std::vector<std::vector<int>> &bikes)
  {
    int m = bikes.size();
    int n = workers.size();

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
      {
        int x1 = bikes[i][0];
        int y1 = bikes[i][1];
        int x2 = workers[j][0];
        int y2 = workers[j][1];
        dist[i][j] = abs(x1 - x2) + abs(y1 - y2);
      }

    int ret = std::numeric_limits<int>::max() / 2;
    std::vector<int> dp(1 << m, std::numeric_limits<int>::max() / 2);
    dp[0] = 0;
    for (int j = 0; j < n; j++)
    {
      int state = (1 << (j + 1)) - 1;
      while (state < (1 << m)) // iterate all state that contain j+1 bits of "1"
      {
        for (int i = 0; i < m; i++)
        {
          if ((state >> i) & 1)
            dp[state] = std::min(dp[state], dp[state - (1 << i)] + dist[i][j]);

          if (j == n - 1)
            ret = std::min(ret, dp[state]);
        }

        int c = state & -state;
        int r = state + c;
        state = (((r ^ state) >> 2) / c) | r;
      }
    }

    return ret;
  }
};
