/**
 * @link https://leetcode.com/problems/median-of-a-row-wise-sorted-matrix/
 */
#include <algorithm>
#include <vector>

class Solution {
public:
  int matrixMedian(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int k = (m * n + 1) / 2;

    int left = 0, right = std::numeric_limits<int>::max();
    while (left < right) {
      int mid = left + (right - left) / 2;
      int count = 0;
      for (int i = 0; i < m; i++)
        count += std::upper_bound(grid[i].begin(), grid[i].end(), mid) - grid[i].begin();
      if (count < k)
        left = mid + 1;
      else
        right = mid;
    }

    return left;
  }
};
