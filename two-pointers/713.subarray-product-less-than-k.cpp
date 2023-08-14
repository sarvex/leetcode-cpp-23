#include <vector>

class Solution {
public:
  int numSubarrayProductLessThanK(std::vector<int> &nums, int k) {
    if (k <= 1) return 0;
    size_t j = 0;
    int prod = 1;
    int count = 0;
    for (size_t i = 0; i < nums.size(); i++) {
      if (j < i) {
        j = i;
        prod = 1;
      }

      while (j < nums.size() && prod * nums[j] < k) {
        prod = prod * nums[j];
        j++;
      }
      count += j - i;
      prod = prod / nums[i];
    }
    return count;
  }
};
