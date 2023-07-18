#include <vector>

class Solution
{
  int m, n;
  vector<vector<int>> result;

public:
  int maxSideLength(std::vector<std::vector<int>> &mat, int threshold)
  {
    m = mat.size();
    n = mat[0].size();

    result.resize(m + 1);
    for (int i = 0; i <= m; i++)
      result[i].resize(n + 1);

    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++)
        result[i][j] = result[i - 1][j] + result[i][j - 1] - result[i - 1][j - 1] + mat[i - 1][j - 1];

    int left = 0, right = min(m, n);
    while (left < right)
    {
      int mid = right - (right - left) / 2;
      if (isOK(mid, threshold))
        left = mid;
      else
        right = mid - 1;
    }
    return left;
  }

  bool isOK(int len, int threshold)
  {
    for (int i = len; i <= m; i++)
      for (int j = len; j <= n; j++)
      {
        int sum = result[i][j] - result[i][j - len] - result[i - len][j] + result[i - len][j - len];
        if (sum <= threshold)
          return true;
      }
    return false;
  }
};
