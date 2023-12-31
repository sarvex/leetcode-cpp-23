#include <string>
#include <vector>

class Solution {
  int dp[16][16];
  std::vector<std::vector<std::string>> rets;
  int n;
  std::string s;

public:
  std::vector<std::vector<std::string>> partition(std::string s) {
    this->s = s;
    n = s.size();

    for (int i = 0; i < n; i++)
      dp[i][i] = 1;
    for (int i = 0; i + 1 < n; i++)
      dp[i][i + 1] = s[i] == s[i + 1];
    for (int len = 3; len <= n; len++)
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1];
        else
          dp[i][j] = 0;
      }

    std::vector<std::string> temp;
    dfs(0, temp);

    return rets;
  }

  void dfs(int i, std::vector<std::string> &temp) {
    if (i == n) {
      rets.push_back(temp);
      return;
    }
    for (int j = i; j < n; j++) {
      if (dp[i][j]) {
        temp.push_back(s.substr(i, j - i + 1));
        dfs(j + 1, temp);
        temp.pop_back();
      }
    }
  }
};
