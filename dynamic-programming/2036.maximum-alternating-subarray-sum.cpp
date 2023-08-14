#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  long long maximumAlternatingSubarraySum(std::vector<int> &nums) {
    long long ret = std::numeric_limits<int>::min();
    long long curSum0 = std::numeric_limits<int>::min();
    long long curSum1 = 0;

    for (long long x: nums) {
      long long curSum0_temp = curSum0;
      long long curSum1_temp = curSum1;
      curSum0 = std::max(curSum1_temp + x, x);
      curSum1 = curSum0_temp - x;

      ret = std::max(ret, curSum0);
      ret = std::max(ret, curSum1);
    }
    return ret;
  }
};
