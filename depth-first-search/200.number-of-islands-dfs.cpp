#include <utility>
#include <vector>

class Solution {
private:
  int M;
  int N;
  std::vector<std::pair<int, int>> dir = std::vector<std::pair<int, int>>{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
  int numIslands(std::vector<std::vector<char>> &grid) {
    M = grid.size();
    if (M == 0) return 0;
    N = grid[0].size();
    auto visited = std::vector<std::vector<int>>(M, std::vector<int>(N, 0));

    int count = 0;

    for (int i = 0; i < M; i++)
      for (int j = 0; j < N; j++) {
        if (grid[i][j] == '0' || visited[i][j] == 1) continue;

        visited[i][j] = 1;
        explore(grid, visited, i, j);
        count++;
      }

    return count;
  }

  void explore(std::vector<std::vector<char>> &grid, std::vector<std::vector<int>> &visited, int i, int j) {
    for (int k = 0; k < 4; k++) {
      int m = i + dir[k].first;
      int n = j + dir[k].second;

      if (m >= 0 && m < M && n >= 0 && n < N && grid[m][n] == '1' && visited[m][n] == 0) {
        visited[m][n] = 1;
        explore(grid, visited, m, n);
      }
    }
    return;
  }
};
