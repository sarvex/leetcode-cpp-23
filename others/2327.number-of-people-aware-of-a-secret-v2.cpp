#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    std::vector<long long> dp(n + 1);// dp[i]: # of new persons who know the news in the i-th day
    std::vector<long long> diff(n + 1);

    dp[1] = 1;
    diff[1] += 1;
    diff[2] += -1;

    long long ret = 0;
    for (int i = 1; i <= n; i++) {
      dp[i] = (dp[i - 1] + diff[i] + M) % M;

      if (i + delay <= n)
        diff[i + delay] += dp[i];
      if (i + forget <= n)
        diff[i + forget] -= dp[i];
    }

    for (int i = 1; i <= n; i++)
      if (i + forget > n)
        ret = (ret + dp[i]) % M;
    return ret;
  }
};
