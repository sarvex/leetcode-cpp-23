#include <algorithm>
#include <vector>

class Solution {
public:
  int maxCoins(std::vector<int> &nums) {
    int N = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    auto dp = std::vector<std::vector<int>>(N + 2, std::vector<int>(N + 2, 0));

    for (int len = 1; len <= N; len++)
      for (int i = 1; i + len - 1 <= N; i++) {
        int j = i + len - 1;
        for (int k = i; k <= j; k++)
          dp[i][j] = std::max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[i - 1] * nums[k] * nums[j + 1]);
      }

    return dp[1][N];
  }
};
