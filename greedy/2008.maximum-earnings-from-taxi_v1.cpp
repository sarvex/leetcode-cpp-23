#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  long long maxTaxiEarnings(int n, std::vector<std::vector<int>> &rides) {
    std::vector<long long> dp(n + 1);
    std::unordered_map<int, std::vector<std::pair<int, int>>> Map;// endTime -> {startTime, gain}
    for (auto ride: rides)
      Map[ride[1]].push_back({ride[0], ride[1] - ride[0] + ride[2]});

    for (int i = 1; i <= n; i++) {
      dp[i] = dp[i - 1];
      for (auto ride: Map[i]) {
        int start = ride.first, gain = ride.second;
        dp[i] = std::max(dp[i], dp[start] + ride.second);
      }
    }
    return dp[n];
  }
};
