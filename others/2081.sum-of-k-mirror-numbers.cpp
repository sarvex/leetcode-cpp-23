#include <numeric>
#include <vector>

class Solution {
  int temp[100];

public:
  long long kMirror(int k, int n) {
    int len = 1;
    std::vector<long long> rets;

    while (1) {
      for (long long i = pow(10, len - 1); i < pow(10, len); i++) {
        long long a = getPalindrome(i, 0);
        if (checkOK(a, k))
          rets.push_back(a);
        if (rets.size() == n)
          return std::accumulate(rets.begin(), rets.end(), 0LL);
      }
      for (long long i = pow(10, len - 1); i < pow(10, len); i++) {
        long long a = getPalindrome(i, 1);
        if (checkOK(a, k))
          rets.push_back(a);
        if (rets.size() == n)
          return std::accumulate(rets.begin(), rets.end(), 0LL);
      }
      len++;
    }
  }

  long long getPalindrome(long long x, int flag) {
    long long y = x;
    long long z = 0;
    int count = 0;
    while (y > 0) {
      count++;
      z = z * 10 + (y % 10);
      y /= 10;
    }

    if (flag == 0) x /= 10;

    for (int i = 0; i < count; i++)
      x = x * 10;

    return x + z;
  }

  bool checkOK(long long x, int k) {
    int t = 0;
    while (x > 0) {
      temp[t] = x % k;
      x /= k;
      t++;
    }
    int i = 0, j = t - 1;
    while (i < j) {
      if (temp[i] != temp[j])
        return false;
      i++;
      j--;
    }
    return true;
  }
};
