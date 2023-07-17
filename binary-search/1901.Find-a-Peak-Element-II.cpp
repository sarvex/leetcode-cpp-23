/**
 * @link https://leetcode.com/problems/find-a-peak-element-ii/
 */
#include <algorithm>
#include <vector>

class Solution
{
public:
  std::vector<int> findPeakGrid(std::vector<std::vector<int>> &mat)
  {
    int m = mat.size();
    int up = 0, low = m - 1;
    while (up <= low)
    {
      int mid = up + (low - up) / 2;

      int upper_max = mid == 0 ? -1 : *max_element(mat[mid - 1].begin(), mat[mid - 1].end());
      int mid_max = *max_element(mat[mid].begin(), mat[mid].end());
      int lower_max = mid == m - 1 ? -1 : *max_element(mat[mid + 1].begin(), mat[mid + 1].end());

      int mx = std::max(upper_max, std::max(mid_max, lower_max));
      if (mx == mid_max)
        return {mid, int(max_element(mat[mid].begin(), mat[mid].end()) - mat[mid].begin())};
      else if (mx == upper_max)
        low = mid - 1;
      else
        up = mid + 1;
    }

    return {-1, -1};
  }
};
