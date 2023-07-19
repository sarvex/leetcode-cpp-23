#include <algorithm>
#include <array>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  std::vector<std::pair<int, int>> next[500];

public:
  int shortestPathWithHops(int n, std::vector<std::vector<int>> &edges, int source, int destination, int k) {
    for (auto &edge: edges) {
      int a = edge[0], b = edge[1], w = edge[2];
      next[a].push_back({b, w});
      next[b].push_back({a, w});
    }
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
    pq.push({0, source, k});

    std::vector<std::vector<int>> dist(n, std::vector<int>(k + 1, std::numeric_limits<int>::max() / 2));

    while (!pq.empty()) {
      auto [d, cur, t] = pq.top();
      pq.pop();
      if (dist[cur][t] != std::numeric_limits<int>::max() / 2) continue;
      dist[cur][t] = d;
      if (cur == destination) return d;

      for (auto [nxt, weight]: next[cur]) {
        if (dist[nxt][t] == std::numeric_limits<int>::max() / 2)
          pq.push({d + weight, nxt, t});
        if (t >= 1 && dist[nxt][t - 1] == std::numeric_limits<int>::max() / 2)
          pq.push({d, nxt, t - 1});
      }
    }
    return -1;
  }
};
