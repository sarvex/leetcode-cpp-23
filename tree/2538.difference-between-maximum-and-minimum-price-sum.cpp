#include <algorithm>
#include <utility>
#include <vector>

class Solution {
  std::vector<int> next[100005];
  long long sum1[100005];// sum1[node]: the maximum path from node to its non-leaf child
  long long sum2[100005];// sum2[node]: the maximum path from node to its leaf child
  long long ret = 0;

public:
  long long maxOutput(int n, std::vector<std::vector<int>> &edges, std::vector<int> &price) {
    if (n == 1) return 0;

    for (auto &edge: edges) {
      int a = edge[0], b = edge[1];
      next[a].push_back(b);
      next[b].push_back(a);
    }

    dfs(0, -1, price);

    dfs2(0, -1, price);

    return ret;
  }

  void dfs(int cur, int parent, std::vector<int> &price) {
    if (next[cur].size() == 1 && next[cur][0] == parent) {
      sum1[cur] = 0;
      sum2[cur] = price[cur];
      return;
    }

    long long maxSum1 = 0, maxSum2 = 0;
    for (int nxt: next[cur]) {
      if (nxt == parent) continue;
      dfs(nxt, cur, price);
      maxSum1 = std::max(maxSum1, sum1[nxt]);
      maxSum2 = std::max(maxSum2, sum2[nxt]);
    }
    sum1[cur] = maxSum1 + price[cur];
    sum2[cur] = maxSum2 + price[cur];
  }

  void dfs2(int cur, int parent, std::vector<int> &price) {
    std::vector<std::pair<long long, int>> arr1;// {SumVal, childNodeId}
    std::vector<std::pair<long long, int>> arr2;

    long long ans = sum1[cur];
    if (cur != 0) ans = std::max(ans, sum2[cur]);

    for (int nxt: next[cur]) {
      if (nxt == parent) continue;
      arr1.push_back({sum1[nxt], nxt});
      arr2.push_back({sum2[nxt], nxt});
      dfs2(nxt, cur, price);
    }
    sort(arr1.rbegin(), arr1.rend());
    sort(arr2.rbegin(), arr2.rend());

    if (arr1.size() >= 2) {
      if (arr1[0].second != arr2[0].second)
        ans = std::max(ans, arr1[0].first + arr2[0].first + price[cur]);
      else
        ans = std::max(ans, std::max(arr1[0].first + arr2[1].first, arr1[1].first + arr2[0].first) + price[cur]);
    }

    ret = std::max(ret, ans);
  }
};


// Find a maximum path, for which one end is leaf, and the other is not.
