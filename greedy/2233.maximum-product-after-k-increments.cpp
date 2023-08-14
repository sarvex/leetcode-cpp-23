#include <algorithm>
#include <vector>

class Solution {
  static const long long M = 1e9 + 7;

public:
  int maximumProduct(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();

    std::vector<long long> presum(n);
    for (int i = 0; i < n; i++)
      presum[i] = (i == 0 ? 0 : presum[i - 1]) + (long long) nums[i];

    std::vector<long long> diff(n);
    for (int i = 0; i < n; i++)
      diff[i] = (long long) nums[i] * (i + 1) - presum[i];

    auto iter = upper_bound(diff.begin(), diff.end(), k);
    int p = prev(iter) - diff.begin();

    long long total = presum[p] + k;
    long long each = total / (p + 1);
    long long extra = total % (p + 1);

    long long ret = 1;
    for (int i = 0; i < extra; i++)
      ret = ret * (each + 1) % M;
    for (int i = extra; i < p + 1; i++)
      ret = ret * (each) % M;
    for (int i = p + 1; i < n; i++)
      ret = ret * nums[i] % M;

    return ret;
  }
};
