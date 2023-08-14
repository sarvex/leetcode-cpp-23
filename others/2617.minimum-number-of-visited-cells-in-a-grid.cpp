#include <algorithm>
#include <queue>
#include <set>
#include <vector>

class Solution {
public:
  int minimumVisitedCells(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, std::numeric_limits<int>::max() / 2));
    std::vector<std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>>> row_diff(m);
    std::vector<std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>>> col_diff(n);
    std::vector<std::multiset<int>> row_set(m);
    std::vector<std::multiset<int>> col_set(n);

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        while (!row_diff[i].empty() && row_diff[i].top().first == j) {
          int x = row_diff[i].top().second;
          row_diff[i].pop();
          if (x > 0) row_set[i].insert(x);
          if (x < 0) row_set[i].erase(row_set[i].find(-x));
        }
        while (!col_diff[j].empty() && col_diff[j].top().first == i) {
          int x = col_diff[j].top().second;
          col_diff[j].pop();
          if (x > 0) col_set[j].insert(x);
          if (x < 0) col_set[j].erase(col_set[j].find(-x));
        }

        int min_val = std::numeric_limits<int>::max() / 2;
        if (!row_set[i].empty()) min_val = std::min(min_val, *row_set[i].begin());
        if (!col_set[j].empty()) min_val = std::min(min_val, *col_set[j].begin());
        dp[i][j] = min_val;
        if (i == 0 && j == 0) dp[0][0] = 0;

        int step = grid[i][j];
        if (step == 0) continue;
        row_diff[i].push({j + 1, dp[i][j] + 1});
        row_diff[i].push({j + 1 + step, -(dp[i][j] + 1)});
        col_diff[j].push({i + 1, dp[i][j] + 1});
        col_diff[j].push({i + 1 + step, -(dp[i][j] + 1)});
      }

    if (dp[m - 1][n - 1] == std::numeric_limits<int>::max() / 2)
      return -1;
    return dp[m - 1][n - 1] + 1;
  }
};
