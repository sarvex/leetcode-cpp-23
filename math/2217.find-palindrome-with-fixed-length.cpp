#include <vector>

class Solution {
public:
  std::vector<long long> kthPalindrome(std::vector<int> &queries, int intLength) {
    std::vector<long long> rets;
    for (int k: queries) {
      if (intLength == 1) {
        if (k > 9) rets.push_back(-1);
        else
          rets.push_back(k);
      } else if (intLength % 2 == 0) {
        int m = intLength / 2;
        long long a = getKth(m, k);
        if (a == -1) {
          rets.push_back(-1);
          continue;
        }
        long long b = flip(a);
        rets.push_back(a * pow(10, m) + b);
      } else {
        int m = intLength / 2;
        long long a = getKth(m + 1, k);
        if (a == -1) {
          rets.push_back(-1);
          continue;
        }
        long long c = a % 10;
        a = a / 10;
        long long b = flip(a);
        rets.push_back(a * pow(10, m + 1) + c * pow(10, m) + b);
      }
    }
    return rets;
  }

  long long getKth(int m, int k) {
    if (k > 9 * pow(10, m - 1)) return -1;
    else
      return pow(10, m - 1) + k - 1;
  }

  long long flip(long long a) {
    long long ret = 0;
    while (a > 0) {
      ret = ret * 10 + (a % 10);
      a /= 10;
    }
    return ret;
  }
};
