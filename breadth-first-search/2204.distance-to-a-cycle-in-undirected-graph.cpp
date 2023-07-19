#include <queue>
#include <vector>

class Solution {
public:
  std::vector<int> distanceToCycle(int n, std::vector<std::vector<int>> &edges) {
    std::vector<int> degree(n);
    std::vector<std::vector<int>> next(n);
    for (auto edge: edges) {
      int a = edge[0], b = edge[1];
      degree[a]++;
      degree[b]++;
      next[a].push_back(b);
      next[b].push_back(a);
    }

    std::vector<int> rets(n);
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
      if (degree[i] == 1)
        q.push(i);
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      rets[cur] = -1;
      for (int nxt: next[cur]) {
        degree[nxt]--;
        if (degree[nxt] == 1)
          q.push(nxt);
      }
    }

    while (!q.empty()) q.pop();
    for (int i = 0; i < n; i++) {
      if (rets[i] == 0)
        q.push(i);
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int nxt: next[cur]) {
        if (rets[nxt] != -1) continue;
        rets[nxt] = rets[cur] + 1;
        q.push(nxt);
      }
    }
    return rets;
  }
};
