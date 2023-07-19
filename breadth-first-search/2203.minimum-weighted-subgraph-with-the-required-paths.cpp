#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  int n;

public:
  long long minimumWeight(int n, std::vector<std::vector<int>> &edges, int src1, int src2, int dest) {
    this->n = n;
    std::vector<std::vector<std::pair<int, int>>> next(n);
    std::vector<std::vector<std::pair<int, int>>> prev(n);
    for (auto edge: edges) {
      int a = edge[0], b = edge[1], w = edge[2];
      next[a].push_back({b, w});
      prev[b].push_back({a, w});
    }

    std::vector<long long> AtoOthers = dijkstra(src1, next);
    std::vector<long long> BtoOthers = dijkstra(src2, next);
    std::vector<long long> CtoOthers = dijkstra(dest, prev);

    long long ret = std::numeric_limits<long long>::max() / 3;
    for (int i = 0; i < n; i++)
      ret = std::min(ret, AtoOthers[i] + BtoOthers[i] + CtoOthers[i]);

    if (ret == std::numeric_limits<long long>::max() / 3)
      return -1;
    else
      return ret;
  }

  std::vector<long long> dijkstra(int start, std::vector<std::vector<std::pair<int, int>>> &adj) {
    std::vector<long long> dist(n, std::numeric_limits<long long>::max() / 3);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
      auto [d, c] = pq.top();
      pq.pop();
      if (dist[c] < std::numeric_limits<long long>::max() / 3)
        continue;
      dist[c] = d;

      for (auto x: adj[c]) {
        long long nxt = x.first, len = x.second;
        if (dist[nxt] < std::numeric_limits<long long>::max() / 3) continue;
        pq.push({d + len, nxt});
      }
    }
    return dist;
  }
};
