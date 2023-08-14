#include <algorithm>
#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

public:
  int sumOfPower(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    long long sum = 0;
    long long ret = 0;

    for (size_t i = 0; i < nums.size(); i++) {
      long long mx = (long long) nums[i] * (long long) nums[i] % M;

      if (i >= 1)
        sum = sum * 2 % M + (long long) nums[i - 1];

      ret += mx * sum % M + mx * nums[i] % M;
      ret %= M;
    }

    return ret;
  }
};
