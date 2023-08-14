#include <algorithm>
#include <vector>

class Solution {
public:
  int minimumTotal(std::vector<std::vector<int>> &triangle) {
    int n = triangle.size();
    std::vector<int> dp(n);
    dp[0] = triangle[0][0];
    for (int i = 1; i < n; i++) {
      auto dp2 = dp;
      for (int j = 0; j <= i; j++) {
        if (j == 0)
          dp[j] = dp2[0] + triangle[i][0];
        else if (j == i)
          dp[j] = dp2[i - 1] + triangle[i][j];
        else
          dp[j] = std::min(dp2[j - 1], dp2[j]) + triangle[i][j];
      }
    }
    int ret = std::numeric_limits<int>::max();
    for (int i = 0; i < n; i++)
      ret = std::min(ret, dp[i]);
    return ret;
  }
};
