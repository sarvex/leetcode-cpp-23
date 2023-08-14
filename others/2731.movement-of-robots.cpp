#include <algorithm>
#include <string>
#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

public:
  int sumDistance(std::vector<int> &nums, std::string s, int d) {
    int n = nums.size();
    std::vector<long long> pos;
    for (int i = 0; i < n; i++) {
      long long p;
      if (s[i] == 'L')
        p = nums[i] - d;
      else
        p = nums[i] + d;
      pos.push_back(p);
    }
    std::sort(pos.begin(), pos.end());

    long long ret = 0;
    for (int i = 0; i + 1 < n; i++) {
      long long s = (pos[i + 1] - pos[i]) % M;
      ret += s * (i + 1) % M * (n - 1 - i) % M;
      ret %= M;
    }

    return ret;
  }
};
