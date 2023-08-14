#include <string>

class Solution {
  long long dp[26];
  long long M = 1e9 + 7;

public:
  int distinctSubseqII(std::string s) {
    for (char ch: s) {
      long long sum = 0;
      for (int i = 0; i < 26; i++)
        sum = (sum + dp[i]) % M;

      dp[ch - 'a'] = sum + 1;
    }

    long long ret = 0;
    for (int i = 0; i < 26; i++)
      ret = (ret + dp[i]) % M;
    return ret;
  }
};
