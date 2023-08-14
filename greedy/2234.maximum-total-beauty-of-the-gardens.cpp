#include <algorithm>
#include <vector>

class Solution {
public:
  long long maximumBeauty(std::vector<int> &flowers, long long newFlowers, int target, int full, int partial) {
    std::sort(flowers.begin(), flowers.end());

    long long ret0 = 0;
    while (flowers.size() > 0 && flowers.back() >= target) {
      ret0 += full;
      flowers.pop_back();
    }
    if (flowers.empty()) return ret0;

    long long n = flowers.size();
    std::vector<long long> presum(n);
    for (long long i = 0; i < n; i++)
      presum[i] = (i == 0 ? 0 : presum[i - 1]) + flowers[i];
    std::vector<long long> diff(n);
    for (long long i = 0; i < n; i++)
      diff[i] = (i + 1) * flowers[i] - presum[i];

    long long ret = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (newFlowers < 0) break;

      if (presum[i] + newFlowers >= (long long) (target - 1) * (i + 1)) {
        ret = std::max(ret, (long long) (target - 1) * partial + (long long) (n - 1 - i) * full);
      } else {
        auto iter = upper_bound(diff.begin(), diff.begin() + i + 1, newFlowers);
        int k = prev(iter) - diff.begin();
        long long total = presum[k] + newFlowers;
        long long each = total / (long long) (k + 1);
        ret = std::max(ret, each * partial + (long long) (n - 1 - i) * full);
      }
      newFlowers -= target - flowers[i];
    }

    if (newFlowers >= 0)
      ret = std::max(ret, n * full);

    return ret + ret0;
  }
};
