/**
 * @link https://leetcode.com/problems/house-robber-iv/
 */
#include <algorithm>
#include <limits>
#include <vector>

class Solution
{
  int dp[100005][2];

public:
  int minCapability(std::vector<int> &nums, int k)
  {
    int left = 0, right = std::numeric_limits<int>::max() / 2;
    while (left < right)
    {
      int mid = left + (right - left) / 2;
      if (atLeastK(mid, nums, k))
        right = mid;
      else
        left = mid + 1;
    }
    return left;
  }

  bool atLeastK(int cap, std::vector<int> &nums, int k)
  {
    int n = nums.size();
    dp[0][0] = 0;
    if (nums[0] <= cap)
      dp[0][1] = 1;
    else
      dp[0][1] = std::numeric_limits<int>::max() / 2;

    for (int i = 1; i < n; i++)
    {
      if (nums[i] > cap)
      {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = std::numeric_limits<int>::max() / 2;
      }
      else
      {
        dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + 1;
      }
    }

    return std::max(dp[n - 1][0], dp[n - 1][1]) >= k;
  }
};
