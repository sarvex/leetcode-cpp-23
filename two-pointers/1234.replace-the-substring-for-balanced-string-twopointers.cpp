#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
  int n;
  std::unordered_map<char, int> count;

public:
  int balancedString(std::string s) {
    n = s.size();
    for (auto ch: s)
      count[ch] += 1;
    int flag = 1;
    for (auto x: count)
      if (x.second != n / 4)
        flag = 0;
    if (flag == 1) return 0;

    int j = 0;
    std::unordered_map<char, int> sum;
    int ret = std::numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
      while (j < n && !isOK(sum)) {
        sum[s[j]] += 1;
        j++;
      }
      if (isOK(sum))
        ret = std::min(ret, j - i);
      sum[s[i]] -= 1;
    }
    return ret;
  }

  bool isOK(std::unordered_map<char, int> &sum) {
    for (auto x: count) {
      char ch = x.first;
      if (count[ch] - sum[ch] > n / 4)
        return false;
    }
    return true;
  }
};
