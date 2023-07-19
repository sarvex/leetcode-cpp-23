#include <algorithm>
#include <array>
#include <utility>
#include <vector>

long long M = 1e9 + 7;
class Solution {
public:
  int countPaths(std::vector<std::vector<int>> &grid) {
    std::vector<std::array<int, 3>> array;
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        array.push_back({grid[i][j], i, j});

    sort(array.begin(), array.end());

    std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 0));
    std::vector<std::pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    long long ret = 0;
    for (auto &[v, i, j]: array) {
      long long sum = 0;
      for (int k = 0; k < 4; k++) {
        int x = i + dir[k].first;
        int y = j + dir[k].second;
        if (x < 0 || x >= m || y < 0 || y >= n) continue;
        if (grid[x][y] >= grid[i][j]) continue;
        sum = (sum + dp[x][y]) % M;
      }
      sum = (sum + 1) % M;
      dp[i][j] = sum;
      ret = (ret + sum) % M;
    }

    return ret;
  }
};
