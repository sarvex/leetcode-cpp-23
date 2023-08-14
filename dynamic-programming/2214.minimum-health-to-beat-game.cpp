#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  long long minimumHealth(std::vector<int> &damage, int armor) {
    int n = damage.size();
    long long dp0 = 0;
    long long dp1 = 0;
    long long ret = std::numeric_limits<long long>::max();
    for (int i = 0; i < n; i++) {
      long long dp0_tmp = dp0, dp1_tmp = dp1;
      dp0 = dp0_tmp - damage[i];
      dp1 = std::max(dp1_tmp - damage[i], dp0_tmp + std::min(armor, damage[i]) - damage[i]);

      ret = std::min(ret, std::max(dp0, dp1));
    }
    return ret > 0 ? 0 : (-ret + 1);
  }
};
