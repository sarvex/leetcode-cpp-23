#include <algorithm>
#include <vector>

class Solution {
public:
  long long mostPoints(std::vector<std::vector<int>> &questions) {
    int n = questions.size();
    std::vector<long long> dp(n + 1);
    for (int i = n - 1; i >= 0; i--) {
      int j = i + questions[i][1] + 1;
      dp[i] = std::max(dp[i + 1], (j < n ? dp[j] : 0) + questions[i][0]);
    }
    return dp[0];
  }
};
