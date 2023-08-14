#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
public:
  int mincostTickets(std::vector<int> &days, std::vector<int> &costs) {
    std::vector<int> dp(400, std::numeric_limits<int>::max());
    std::unordered_set<int> Set(days.begin(), days.end());
    dp[0] = 0;
    for (int i = 1; i <= 365; i++) {
      if (Set.find(i) == Set.end()) {
        dp[i] = dp[i - 1];
        continue;
      }
      int a = dp[std::max(0, i - 1)] + costs[0];
      int b = dp[std::max(0, i - 7)] + costs[1];
      int c = dp[std::max(0, i - 30)] + costs[2];
      dp[i] = std::min(a, std::min(b, c));
    }

    return dp[365];
  }
};
