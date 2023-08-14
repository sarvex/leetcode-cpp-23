#include <vector>

class Solution {
  long long dp[105][20005];
  long long offset = 10000;
  long long M = 1e9 + 7;

public:
  int countSubranges(std::vector<int> &nums1, std::vector<int> &nums2) {
    int n = nums1.size();
    nums1.insert(nums1.begin(), 0);
    nums2.insert(nums2.begin(), 0);

    dp[1][0 + offset] = 0;
    long long ret = 0;

    for (int i = 1; i <= n; i++) {
      dp[i][offset + nums1[i]] += 1;
      dp[i][offset - nums2[i]] += 1;

      for (int sum = -offset; sum <= offset; sum++) {
        if (inbound(sum - nums1[i])) {
          dp[i][sum + offset] += dp[i - 1][sum + offset - nums1[i]];
          dp[i][sum + offset] %= M;
        }

        if (inbound(sum + nums2[i])) {
          dp[i][sum + offset] += dp[i - 1][sum + offset + nums2[i]];
          dp[i][sum + offset] %= M;
        }
      }

      ret += dp[i][0 + offset];
      ret %= M;
    }

    return ret;
  }

  bool inbound(int x) {
    return x >= -offset && x <= offset;
  }
};
