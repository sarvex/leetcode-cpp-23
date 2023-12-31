#include <algorithm>
#include <vector>

class Solution {
  int dp[1001];
  int d;

public:
  int maxJumps(std::vector<int> &arr, int d) {
    this->d = d;

    int ret = 0;
    for (int i = 0; i < arr.size(); i++) {
      dfs(i, arr);
      ret = std::max(ret, dp[i]);
    }
    return ret;
  }

  int dfs(int i, std::vector<int> &arr) {
    if (dp[i] != 0) return dp[i];

    int ret = 1;

    for (int k = 1; k <= d; k++) {
      if (i + k >= arr.size()) break;
      if (arr[i + k] >= arr[i]) break;
      ret = std::max(ret, dfs(i + k, arr) + 1);
    }
    for (int k = 1; k <= d; k++) {
      if (i - k < 0) break;
      if (arr[i - k] >= arr[i]) break;
      ret = std::max(ret, dfs(i - k, arr) + 1);
    }
    dp[i] = ret;

    return dp[i];
  }
};
