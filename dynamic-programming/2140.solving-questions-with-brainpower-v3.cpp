#include <vector>

class Solution {
public:
  long long mostPoints(std::vector<std::vector<int>> &questions) {
    int n = questions.size();
    std::vector<std::vector<long long>> dp(n, std::vector<long long>(2));
    dp[0][1] = questions[0][0];

    std::vector<long long> base(n);
    long long diff = 0;

    long long maxPre = 0;
    for (int i = 0; i < n; ++i) {
      diff = std::max(diff, base[i]);
      dp[i][1] = diff + questions[i][0];

      int skip = questions[i][1];
      if (i + 1 < n)
        dp[i + 1][0] = std::max(dp[i + 1][0], std::max(dp[i][0], dp[i][1]));
      if (i + skip + 1 < n)
        base[i + skip + 1] = std::max(base[i + skip + 1], dp[i][1]);
    }

    return std::max(dp[n - 1][0], dp[n - 1][1]);
  }
};
