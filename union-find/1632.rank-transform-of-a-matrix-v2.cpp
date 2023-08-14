#include <algorithm>
#include <utility>
#include <vector>

class Solution {
  std::vector<int> Father;
  int FindFather(int x) {
    if (Father[x] != x)
      Father[x] = FindFather(Father[x]);
    return Father[x];
  }

  void Union(int x, int y) {
    x = Father[x];
    y = Father[y];
    if (x < y)
      Father[y] = x;
    else
      Father[x] = y;
  }

public:
  std::vector<std::vector<int>> matrixRankTransform(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    Father.resize(m * n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        Father[i * n + j] = i * n + j;

    for (int i = 0; i < m; i++) {
      std::vector<std::pair<int, int>> temp;
      for (int j = 0; j < n; j++)
        temp.push_back({matrix[i][j], i * n + j});
      sort(temp.begin(), temp.end());
      for (int j = 1; j < n; j++) {
        if (temp[j].first == temp[j - 1].first) {
          if (FindFather(temp[j - 1].second) != FindFather(temp[j].second))
            Union(temp[j - 1].second, temp[j].second);
        }
      }
    }

    for (int j = 0; j < n; j++) {
      std::vector<std::pair<int, int>> temp;
      for (int i = 0; i < m; i++)
        temp.push_back({matrix[i][j], i * n + j});
      sort(temp.begin(), temp.end());
      for (int i = 1; i < m; i++) {
        if (temp[i].first == temp[i - 1].first) {
          if (FindFather(temp[i - 1].second) != FindFather(temp[i].second))
            Union(temp[i - 1].second, temp[i].second);
        }
      }
    }

    std::vector<std::pair<int, int>> nums;
    std::vector<std::vector<int>> group(m * n);
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++) {
        int root = FindFather(i * n + j);
        group[root].push_back(i * n + j);
        nums.push_back({matrix[i][j], i * n + j});
      }
    sort(nums.begin(), nums.end());

    std::vector<int> rowRank(m, 0);
    std::vector<int> colRank(m, 0);
    auto rets = std::vector<std::vector<int>>(m, std::vector<int>(n));

    for (auto p: nums) {
      int val = p.first;
      int x = p.second / n;
      int y = p.second % n;
      if (rets[x][y] != 0) continue;

      int r = 0;
      for (auto p: group[Father[x * n + y]]) {
        r = std::max(r, rowRank[p / n]);
        r = std::max(r, colRank[p % n]);
      }
      for (auto p: group[Father[x * n + y]]) {
        rowRank[p / n] = r + 1;
        colRank[p % n] = r + 1;
        rets[p / n][p % n] = r + 1;
      }
    }
    return rets;
  }
};
