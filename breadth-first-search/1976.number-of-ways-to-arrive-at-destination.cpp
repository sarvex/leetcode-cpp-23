#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  std::vector<std::vector<long long>> adj[201];
  long long dist[201];
  long long count[201];
  long M = 1e9 + 7;

public:
  int countPaths(int n, std::vector<std::vector<int>> &roads) {
    for (auto road: roads) {
      long long u = road[0], v = road[1], len = road[2];
      adj[u].push_back({v, len});
      adj[v].push_back({u, len});
    }

    for (int i = 0; i < n; i++)
      dist[i] = -1;

    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
      auto [d, c] = pq.top();
      pq.pop();
      if (dist[c] != -1)
        continue;
      if (dist[c] == -1)
        dist[c] = d;

      for (auto x: adj[c]) {
        long long nxt = x[0], len = x[1];
        if (dist[nxt] != -1) continue;
        pq.push({d + len, nxt});
      }
    }

    for (int i = 0; i < n; i++)
      count[i] = -1;
    return dfs(n - 1, dist[n - 1]);
    ;
  }

  long long dfs(int cur, long d) {
    if (d != dist[cur])
      return 0;
    if (cur == 0) return 1;
    if (count[cur] != -1)
      return count[cur];

    long long c = 0;
    for (auto x: adj[cur]) {
      long long nxt = x[0], len = x[1];
      c += dfs(nxt, d - len);
      c %= M;
    }
    count[cur] = c;
    return c;
  }
};
