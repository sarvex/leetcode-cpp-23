#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  int minimumXORSum(std::vector<int> &nums1, std::vector<int> &nums2) {
    int m = nums1.size();
    std::vector<int> dp(1 << m, std::numeric_limits<int>::max() / 2);
    std::vector<int> dp2(1 << m);
    dp[0] = 0;

    for (int i = 0; i < m; i++) {
      dp2 = dp;

      int k = i + 1;
      int state = (1 << k) - 1;
      while (state < (1 << m)) {
        dp[state] = std::numeric_limits<int>::max() / 2;
        for (int j = 0; j < m; j++) {
          if ((state >> j) & 1) {
            dp[state] = std::min(dp[state], dp2[state - (1 << j)] + (nums1[j] ^ nums2[i]));
          }
        }
        int c = state & -state;
        int r = state + c;
        state = (((r ^ state) >> 2) / c) | r;
      }
    }
    return dp[(1 << m) - 1];
  }
};
