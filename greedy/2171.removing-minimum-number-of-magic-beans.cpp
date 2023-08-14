#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  long long minimumRemoval(std::vector<int> &beans) {
    std::sort(beans.rbegin(), beans.rend());
    long long total = accumulate(beans.begin(), beans.end(), 0LL);

    long long ret = std::numeric_limits<long long>::max();
    for (int i = 0; i < beans.size(); i++) {
      ret = std::min(ret, total - (long long) beans[i] * (i + 1));
    }
    return ret;
  }
};
