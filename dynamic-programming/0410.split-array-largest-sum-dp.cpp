#include <algorithm>
#include <vector>

class Solution {
public:
  int splitArray(std::vector<int> &nums, int m) {
    int N = nums.size();
    auto dp = std::vector<std::vector<long>>(N + 1, std::vector<long>(m + 1, std::numeric_limits<int>::max()));
    nums.insert(nums.begin(), 0);

    dp[0][0] = 0;

    for (int i = 1; i <= N; i++)
      for (int k = 1; k <= std::min(m, i); k++) {
        long sum = 0;
        for (int j = i; j >= k; j--) {
          sum += nums[j];
          dp[i][k] = std::min(dp[i][k], std::max(dp[j - 1][k - 1], sum));
        }
      }

    return dp[N][m];
  }
};
