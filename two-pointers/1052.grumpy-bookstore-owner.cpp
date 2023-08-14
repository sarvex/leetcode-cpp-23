#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSatisfied(std::vector<int> &customers, std::vector<int> &grumpy, int X) {
    int sum = 0;
    int n = grumpy.size();
    for (int i = 0; i < n; i++)
      if (grumpy[i] == 0)
        sum += customers[i];

    int ret = 0;
    for (int i = 0; i < n; i++) {
      if (grumpy[i] == 1)
        sum += customers[i];
      if (i >= X && grumpy[i - X] == 1)
        sum -= customers[i - X];
      ret = std::max(ret, sum);
    }
    return ret;
  }
};
