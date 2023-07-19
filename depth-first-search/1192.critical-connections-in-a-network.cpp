#include <algorithm>
#include <vector>

class Solution {
  std::vector<std::vector<int>> rets;
  std::vector<std::vector<int>> next;
  int time = 0;

public:
  std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>> &connections) {
    next.resize(n);
    for (auto x: connections) {
      next[x[0]].push_back(x[1]);
      next[x[1]].push_back(x[0]);
    }

    std::vector<bool> visited(n);
    std::vector<int> dfn(n, 0);
    std::vector<int> low(n, 0);
    std::vector<int> parent(n, -1);

    for (int i = 0; i < n; i++) {
      if (visited[i] == false)
        DFS(i, visited, dfn, low, parent);
    }

    return rets;
  }


  void DFS(int u, std::vector<bool> &visited, std::vector<int> &dfn, std::vector<int> &low, std::vector<int> &parent) {
    visited[u] = true;

    dfn[u] = low[u] = ++time;

    for (int v: next[u]) {
      if (v == parent[u])
        continue;

      if (!visited[v]) {
        parent[v] = u;
        DFS(v, visited, dfn, low, parent);

        if (low[v] > dfn[u]) rets.push_back({v, u});// critical edge

        // if(low[v] >= dfn[u]), then u is a critical vertex

        low[u] = std::min(low[u], low[v]);
      } else {
        low[u] = std::min(low[u], dfn[v]);
      }
    }
  }
};
