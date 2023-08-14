#include <string>

class Solution {
  unsigned long long hashes[100001];
  unsigned long long power[100001];

public:
  unsigned long long getHash(std::string &s, int i, int len) {
    return hashes[i + len - 1] - (i == 0 ? 0 : hashes[i - 1] * power[len]);
  }

  long long sumScores(std::string s) {
    int n = s.size();
    unsigned long long hash = 0;
    for (int i = 0; i < n; i++) {
      hash = hash * 26 + (s[i] - 'a');
      hashes[i] = hash;
    }

    power[0] = 1;
    for (int i = 1; i < n; i++) {
      power[i] = power[i - 1] * 26;
    }

    long long ret = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != s[0]) continue;
      int left = 1, right = n - i;
      while (left < right) {
        int mid = right - (right - left) / 2;
        if (getHash(s, i, mid) != hashes[mid - 1])
          right = mid - 1;
        else
          left = mid;
      }
      ret += left;
    }

    return ret;
  }
};
