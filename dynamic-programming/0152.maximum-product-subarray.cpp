#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  int maxProduct(std::vector<int> &nums) {
    long MAX = 1;
    long MIN = 1;
    long result = std::numeric_limits<int>::min();

    for (int i = 0; i < nums.size(); i++) {
      long MAX_tmp = MAX, MIN_tmp = MIN;
      MAX = std::max(std::max(MAX_tmp * nums[i], MIN_tmp * nums[i]), (long) nums[i]);
      MIN = std::min(std::min(MAX_tmp * nums[i], MIN_tmp * nums[i]), (long) nums[i]);
      result = std::max(result, MAX);
    }
    return result;
  }
};
