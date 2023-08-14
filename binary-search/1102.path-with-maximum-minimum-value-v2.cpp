#include <algorithm>
#include <array>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  std::vector<std::pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
  int maximumMinimumPath(std::vector<std::vector<int>> &grid) {
    int M = grid.size();
    int N = grid[0].size();
    std::priority_queue<std::array<int, 3>> pq;

    pq.push({grid[0][0], 0, 0});
    std::vector<std::vector<int>> visited(M, std::vector<int>(N, 0));
    std::vector<std::vector<int>> rets(M, std::vector<int>(N, 0));

    while (pq.size() > 0) {
      auto [d, x, y] = pq.top();
      pq.pop();
      if (visited[x][y] == 1)
        continue;
      rets[x][y] = d;
      visited[x][y] = 1;
      if (x == M - 1 && y == N - 1)
        return d;

      for (int k = 0; k < 4; k++) {
        int i = x + dir[k].first;
        int j = y + dir[k].second;
        if (i < 0 || i >= M || j < 0 || j >= N)
          continue;
        pq.push({std::min(d, grid[i][j]), i, j});
      }
    }

    return -1;
  }
};
