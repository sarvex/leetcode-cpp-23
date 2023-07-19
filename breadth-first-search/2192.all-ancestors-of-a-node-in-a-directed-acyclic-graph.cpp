#include <algorithm>
#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<int>> next(n);
    std::vector<int> indegree(n);
    for (auto edge: edges) {
      int a = edge[0], b = edge[1];
      next[a].push_back(b);
      indegree[b]++;
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }

    std::vector<std::unordered_set<int>> rets(n);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (auto x: next[cur]) {
        for (auto y: rets[cur])
          rets[x].insert(y);
        rets[x].insert(cur);
        indegree[x]--;
        if (indegree[x] == 0)
          q.push(x);
      }
    }

    std::vector<std::vector<int>> ans(n);
    for (int i = 0; i < n; i++)
      for (auto x: rets[i])
        ans[i].push_back(x);


    for (int i = 0; i < n; i++)
      std::sort(ans[i].begin(), ans[i].end());

    return ans;
  }
};
