#include <algorithm>
#include <vector>

class Solution {
  int visited[61];
  std::vector<std::vector<int>> next;

  bool dfs(int cur) {
    if (visited[cur] == 1) return true;

    visited[cur] = 2;
    for (int next: next[cur]) {
      if (visited[next] == 1) continue;
      if (visited[next] == 2) return false;
      if (dfs(next) == false) return false;
    }
    visited[cur] = 1;
    return true;
  }


public:
  bool isPrintable(std::vector<std::vector<int>> &targetGrid) {
    int m = targetGrid.size();
    int n = targetGrid[0].size();
    std::vector<int> left(61, n);
    std::vector<int> right(61, -1);
    std::vector<int> top(61, m);
    std::vector<int> bottom(61, -1);

    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        int color = targetGrid[i][j];
        left[color] = std::min(left[color], j);
        right[color] = std::max(right[color], j);
        top[color] = std::min(top[color], i);
        bottom[color] = std::max(bottom[color], i);
      }

    next.resize(61);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        for (int color = 1; color <= 60; color++) {
          if (i >= top[color] && i <= bottom[color] && j >= left[color] && j <= right[color]) {
            if (color != targetGrid[i][j])
              next[targetGrid[i][j]].push_back(color);
          }
        }
      }

    for (int i = 1; i <= 60; i++) {
      if (dfs(i) == false) return false;
    }

    return true;
  }
};
