#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
  int maxJumps(std::vector<int> &arr, int d) {
    int n = arr.size();
    std::vector<int> dp(n, 1);

    std::vector<std::pair<int, int>> p;
    for (int i = 0; i < n; i++)
      p.push_back({arr[i], i});
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());

    for (auto [height, idx]: p) {
      for (int i = idx + 1; i <= std::min(n - 1, idx + d); i++) {
        if (arr[i] >= arr[idx]) break;
        dp[i] = std::max(dp[i], dp[idx] + 1);
      }
      for (int i = idx - 1; i >= std::max(0, idx - d); i--) {
        if (arr[i] >= arr[idx]) break;
        dp[i] = std::max(dp[i], dp[idx] + 1);
      }
    }

    int ret = 0;
    for (int i = 0; i < n; i++)
      ret = std::max(ret, dp[i]);
    return ret;
  }
};
