#include <algorithm>
#include <vector>

class Solution {
  long long dp[100005][2];

public:
  std::vector<long long> minimumCosts(std::vector<int> &regular, std::vector<int> &express, int expressCost) {
    int n = regular.size();
    regular.insert(regular.begin(), 0);
    express.insert(express.begin(), 0);

    dp[0][0] = 0;
    dp[0][1] = expressCost;

    std::vector<long long> rets;

    for (int i = 1; i <= n; i++) {
      dp[i][0] = std::min(dp[i - 1][0] + regular[i], dp[i - 1][1] + regular[i]);
      dp[i][1] = std::min(dp[i - 1][1] + express[i], dp[i - 1][0] + expressCost + express[i]);

      rets.push_back(std::min(dp[i][0], dp[i][1]));
    }

    return rets;
  }
};
