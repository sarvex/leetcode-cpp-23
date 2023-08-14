#include <unordered_set>
#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

  unsigned long long power[211];
  unsigned long long B = 201;

public:
  int countDistinct(std::vector<int> &nums, int k, int p) {
    int n = nums.size();
    power[0] = 1;
    for (int i = 1; i < B; i++)// power[i] = B^i;
      power[i] = power[i - 1] * B;

    int ret = 0;
    for (int len = 1; len <= n; len++) {
      std::unordered_set<unsigned long long> Set;
      unsigned long long hash = 0;
      int count = 0;

      for (int i = 0; i < n; i++) {
        if (i >= len) {
          hash = (hash - nums[i - len] * power[len - 1] + M) % M;
          count -= (nums[i - len] % p == 0);
        }

        hash = hash * B + nums[i];
        count += (nums[i] % p == 0);

        if (i >= len - 1) {
          if (Set.find(hash) != Set.end()) continue;
          Set.insert(hash);
          if (count <= k)
            ret += 1;
        }
      }
    }
    return ret;
  }
};
