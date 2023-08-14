#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  long long minimumCost(std::string s) {
    long long ret1 = solve(s);
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '1')
        s[i] = '0';
      else
        s[i] = '1';
    long long ret2 = solve(s);
    return std::min(ret1, ret2);
  }

  long long solve(std::string s) {
    int total = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
      total += (s[i] == '1');

    std::vector<long long> left(n);
    int lastOne = -1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        left[i] = sum;
        continue;
      }

      if (i >= 1 && s[i - 1] == '1')
        sum = sum + 1;
      else
        sum += (i + 1) + i;

      left[i] = sum;
      lastOne = i;
    }

    std::vector<long long> right(n);
    lastOne = n;
    sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '0') {
        right[i] = sum;
        continue;
      }

      if (i + 1 < n && s[i + 1] == '1')
        sum = sum + 1;
      else
        sum += (n - i) + (n - i - 1);
      right[i] = sum;
      lastOne = i;
    }

    long long ret = right[0];
    for (int i = 0; i < n - 1; i++)
      ret = std::min(ret, left[i] + right[i + 1]);
    return ret;
  }
};
