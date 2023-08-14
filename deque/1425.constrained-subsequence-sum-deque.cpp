#include <algorithm>
#include <deque>
#include <vector>

class Solution {
public:
  int constrainedSubsetSum(std::vector<int> &nums, int k) {
    int n = nums.size();
    std::vector<int> dp(n, 0);
    std::deque<int> q;

    int ret = std::numeric_limits<int>::min();
    for (int i = 0; i < n; i++) {
      while (q.size() > 0 && q.front() < i - k)
        q.pop_front();

      dp[i] = nums[i];
      if (q.size() > 0) dp[i] = std::max(dp[i], dp[q.front()] + nums[i]);

      while (q.size() > 0 && dp[q.back()] <= dp[i])
        q.pop_back();
      q.push_back(i);
    }

    for (int i = 0; i < n; i++)
      ret = std::max(ret, dp[i]);
    return ret;
  }
};
