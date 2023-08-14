#include <vector>

class Solution {
public:
  long long minimumReplacement(std::vector<int> &nums) {
    long long ret = 0;
    for (int i = nums.size() - 2; i >= 0; i--) {
      long long x = nums[i + 1];
      long long y = nums[i];
      if (y <= x) continue;

      long long k = y / x;
      long long d = y % x;
      if (d == 0) {
        ret += k - 1;
        nums[i] = x;
        continue;
      }

      // d + k*p <= x - p
      long long p = (x - d) / (k + 1);

      long long x2 = x - p;
      long long d2 = d + k * p;

      if (d2 < x2) {
        nums[i] = x2 - 1;
      } else {
        nums[i] = d2;
      }
      ret += k;
    }

    return ret;
  }
};
