#include <algorithm>
#include <string>

class Solution {
public:
  long long minimumCost(std::string s) {
    int n = s.size();
    long long ret = 0;
    for (int i = 1; i < n; i++) {
      if (s[i - 1] != s[i])
        ret += std::min(i, n - i);
    }
    return ret;
  }
};
