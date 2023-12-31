#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int numDistinct(std::string s, std::string t) {
    int m = s.size();
    int n = t.size();
    auto dp = std::vector<std::vector<long long>>(m + 1, std::vector<long long>(n + 1, 0));
    s = "#" + s;
    t = "#" + t;

    if (m < n)
      return 0;
    if (m == n)
      return (s == t);

    for (int i = 0; i <= m; i++)
      dp[i][0] = 1;

    for (int i = 1; i <= m; i++)
      for (int j = 1; j <= n; j++) {
        if (s[i] == t[j])
          dp[i][j] = std::min(LLONG_MAX / 2, dp[i - 1][j] + dp[i - 1][j - 1]);
        else
          dp[i][j] = dp[i - 1][j];
      }
    return dp[m][n];
  }
};
