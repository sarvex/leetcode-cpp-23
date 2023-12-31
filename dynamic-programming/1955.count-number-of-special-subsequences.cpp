#include <vector>

class Solution {
  long long M = 1e9 + 7;

public:
  int countSpecialSubsequences(std::vector<int> &nums) {
    long long dp0 = 1, dp1 = 0, dp2 = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 0)
        dp0 = (dp0 * 2) % M;
      else if (nums[i] == 1)
        dp1 = (dp0 - 1 + dp1 * 2) % M;
      else
        dp2 = (dp1 + dp2 * 2) % M;
    }
    return dp2;
  }
};
