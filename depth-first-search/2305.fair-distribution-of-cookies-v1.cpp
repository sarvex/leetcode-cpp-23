#include <limits>
#include <vector>

class Solution {
  int ret = std::numeric_limits<int>::max();
  int plan[8];

public:
  int distributeCookies(std::vector<int> &cookies, int k) {
    dfs(cookies, k, 0);
    return ret;
  }

  void dfs(std::vector<int> &cookies, int k, int curCookie) {
    if (curCookie == cookies.size()) {
      int mx = 0;
      for (int i = 0; i < k; i++)
        mx = std::max(mx, plan[i]);
      ret = std::min(ret, mx);
      return;
    }

    for (int i = 0; i < k; i++) {
      plan[i] += cookies[curCookie];
      dfs(cookies, k, curCookie + 1);
      plan[i] -= cookies[curCookie];
    }
  }
};
