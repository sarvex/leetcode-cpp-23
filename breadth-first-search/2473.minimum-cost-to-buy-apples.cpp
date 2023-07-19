#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  std::vector<std::pair<int, long long>> next[1005];

public:
  std::vector<long long> minCost(int n, std::vector<std::vector<int>> &roads, std::vector<int> &appleCost, int k) {
    for (auto &road: roads) {
      int a = road[0], b = road[1], c = road[2];
      next[a].push_back({b, c});
      next[b].push_back({a, c});
    }

    std::vector<long long> rets;
    for (int i = 1; i <= n; i++) {
      std::priority_queue<std::pair<int, long long>, std::vector<std::pair<int, long long>>, std::greater<>> pq;
      pq.push({0, i});
      std::vector<long long> visited(n + 1, -1);
      while (!pq.empty()) {
        auto [dist, cur] = pq.top();
        pq.pop();
        if (visited[cur] == -1)
          visited[cur] = dist;

        for (auto [nxt, len]: next[cur]) {
          if (visited[nxt] != -1) continue;
          pq.push({dist + len * (1 + k), nxt});
        }
      }

      long long ret = std::numeric_limits<long long>::max();
      for (int i = 1; i <= n; i++)
        if (visited[i] != -1)
          ret = std::min(ret, appleCost[i - 1] + visited[i]);
      rets.push_back(ret);
    }

    return rets;
  }
};
