#include <algorithm>
#include <vector>

class Solution {
public:
  int maxProduct(std::vector<int> &nums) {
    int n = nums.size();
    std::vector<long> dp1(n);
    std::vector<long> dp2(n);
    dp1[0] = nums[0];
    dp2[0] = nums[0];
    long ret = nums[0];

    for (int i = 1; i < n; i++) {
      dp1[i] = std::max(std::max(dp1[i - 1] * (long) nums[i], dp2[i - 1] * (long) nums[i]), (long) nums[i]);
      dp2[i] = std::min(std::min(dp1[i - 1] * (long) nums[i], dp2[i - 1] * (long) nums[i]), (long) nums[i]);
      ret = std::max(ret, dp1[i]);
    }
    return ret;
  }
};
