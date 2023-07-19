#include <limits>
#include <set>
#include <vector>

class Solution {
public:
  int constrainedSubsetSum(std::vector<int> &nums, int k) {
    int n = nums.size();
    std::multiset<int> Set;
    std::vector<int> dp(n, 0);

    int ret = std::numeric_limits<int>::max();

    for (int i = 0; i < n; i++) {
      if (Set.size() > k && i - k - 1 >= 0)
        Set.erase(Set.lower_bound(dp[i - k - 1]));

      dp[i] = nums[i];
      if (Set.size() > 0) dp[i] = std::max(dp[i], *Set.rbegin() + nums[i]);
      ret = std::max(ret, dp[i]);

      Set.insert(dp[i]);
    }

    return ret;
  }
};
