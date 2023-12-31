#include <algorithm>
#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

public:
  int countWays(std::vector<std::vector<int>> &ranges) {
    std::sort(ranges.begin(), ranges.end());
    int n = ranges.size();
    long long ret = 1;

    for (int i = 0; i < n; i++) {
      int far = ranges[i][1];
      int j = i;
      while (j < n && ranges[j][0] <= far) {
        far = std::max(far, ranges[j][1]);
        j++;
      }
      ret = ret * 2 % M;
      i = j - 1;
    }

    return ret;
  }
};
