#include <vector>

class Solution {
public:
  int closestCost(std::vector<int> &baseCosts, std::vector<int> &toppingCosts, int target) {
    int m = toppingCosts.size();

    int ret = std::numeric_limits<int>::max();
    int ret_diff = std::numeric_limits<int>::max();

    for (int base: baseCosts)
      for (int state = 0; state < pow(3, m); ++state) {
        int s = state;
        int topping = 0;
        for (int i = 0; i < m; ++i) {
          int cur = s % 3;
          topping += toppingCosts[i] * cur;
          s /= 3;
        }

        if (abs(base + topping - target) < ret_diff) {
          ret = base + topping;
          ret_diff = abs(base + topping - target);
        } else if (abs(base + topping - target) == ret_diff && base + topping < ret)
          ret = base + topping;
      }

    return ret;
  }
};
