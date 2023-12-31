#include <utility>
#include <vector>

class Solution {
  int M, N;

public:
  std::vector<std::pair<int, int>> pacificAtlantic(std::vector<std::vector<int>> &matrix) {
    M = matrix.size();
    if (M == 0) return {};
    N = matrix[0].size();

    auto pac = std::vector<std::vector<int>>(M, std::vector<int>(N, 0));
    auto atl = std::vector<std::vector<int>>(M, std::vector<int>(N, 0));

    for (int j = 0; j < N; j++)
      DFS(0, j, matrix, pac);
    for (int i = 1; i < M; i++)
      DFS(i, 0, matrix, pac);
    for (int j = 0; j < N; j++)
      DFS(M - 1, j, matrix, atl);
    for (int i = 0; i < M - 1; i++)
      DFS(i, N - 1, matrix, atl);

    std::vector<std::pair<int, int>> results;
    for (int i = 0; i < M; i++)
      for (int j = 0; j < N; j++) {
        if (atl[i][j] == 1 && pac[i][j] == 1)
          results.push_back({i, j});
      }
    return results;
  }

  void DFS(int i, int j, std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &visited) {
    std::vector<std::pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    for (int k = 0; k < 4; k++) {
      visited[i][j] = 1;
      int m = i + dir[k].first;
      int n = j + dir[k].second;

      if (m < 0 || m == M || n < 0 || n == N) continue;
      if (visited[m][n] == 1) continue;
      if (matrix[m][n] < matrix[i][j]) continue;

      DFS(m, n, matrix, visited);
    }
  }
};
