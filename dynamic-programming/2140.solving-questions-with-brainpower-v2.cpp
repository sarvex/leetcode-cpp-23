#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
  long long mostPoints(std::vector<std::vector<int>> &questions) {
    int n = questions.size();
    std::vector<std::vector<long long>> dp(n, std::vector<long long>(2));
    dp[0][1] = questions[0][0];

    std::vector<std::pair<int, int>> endTimes;
    for (int i = 0; i < n; i++)
      endTimes.push_back({i + questions[i][1], i});
    sort(endTimes.begin(), endTimes.end());
    int p = 0;

    long long maxPre = 0;
    for (int i = 1; i < n; ++i) {
      while (p < n && endTimes[p].first < i) {
        maxPre = std::max(maxPre, dp[endTimes[p].second][1]);
        p++;
      }

      dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = maxPre + questions[i][0];
    }

    return std::max(dp[n - 1][0], dp[n - 1][1]);
  }
};
