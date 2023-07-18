#include <algorithm>
#include <limits>
#include <utility>
#include <vector>

class Solution
{
  int m, n;

public:
  int sminFlips(std::vector<std::vector<int>> &mat)
  {
    m = mat.size();
    n = mat[0].size();
    int ret = std::numeric_limits<int>::max();

    for (int state = 0; state < (1 << (m * n)); state++)
    {
      if (check(mat, state))
        ret = std::min(ret, (int)std::bitset<9>(state).count());
    }
    if (ret == std::numeric_limits<int>::max())
      return -1;
    else
      return ret;
  }

  bool check(std::vector<std::vector<int>> &mat, int state)
  {
    auto temp = mat;
    auto dir = std::vector<std::pair<int, int>>({{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}});

    for (int s = 0; s < (m * n); s++)
    {
      int t = state % 2;
      state /= 2;
      if (t == 0)
        continue;

      int i = s / n;
      int j = s % n;

      for (int k = 0; k < 5; k++)
      {
        int x = i + dir[k].first;
        int y = j + dir[k].second;
        if (x < 0 || x >= m || y < 0 || y >= n)
          continue;
        temp[x][y] = 1 - temp[x][y];
      }
    }

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        if (temp[i][j] != 0)
          return false;
    return true;
  }
};
