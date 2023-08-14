#include <algorithm>
#include <array>
#include <limits>
#include <map>
#include <vector>

class Solution {
public:
  int maxIncreasingCells(std::vector<std::vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    std::vector<std::array<int, 3>> nums;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        nums.push_back({mat[i][j], i, j});
    std::sort(nums.begin(), nums.end());

    std::vector<std::map<int, int>> rows(m);
    std::vector<std::map<int, int>> cols(n);

    for (int i = 0; i < m; i++)
      rows[i].insert({std::numeric_limits<int>::min(), 0});
    for (int j = 0; j < n; j++)
      cols[j].insert({std::numeric_limits<int>::min(), 0});

    int ret = 1;
    for (auto [val, i, j]: nums) {
      int len = 1;

      auto iter = rows[i].lower_bound(val);
      iter = prev(iter);
      len = std::max(len, iter->second + 1);

      iter = cols[j].lower_bound(val);
      iter = prev(iter);
      len = std::max(len, iter->second + 1);

      rows[i][val] = std::max(len, rows[i][val]);
      cols[j][val] = std::max(len, cols[j][val]);

      ret = std::max(ret, len);
    }

    return ret;
  }
};
