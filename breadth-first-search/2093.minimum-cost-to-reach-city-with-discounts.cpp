#include <algorithm>
#include <array>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int minimumCost(int n, std::vector<std::vector<int>> &highways, int discounts) {
    std::vector<std::vector<std::pair<int, int>>> next(n);
    for (auto x: highways) {
      int a = x[0], b = x[1], w = x[2];
      next[a].push_back({b, w});
      next[b].push_back({a, w});
    }

    std::vector<std::vector<int>> cost(n, std::vector<int>(discounts + 1, INT_MAX));       // cost[city][discounts]
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;// {cost, city, discounts}
    pq.push({0, 0, discounts});

    while (!pq.empty()) {
      auto [c, cur, times] = pq.top();
      pq.pop();

      if (c >= cost[cur][times]) continue;
      cost[cur][times] = c;
      if (cur == n - 1) return c;

      for (auto x: next[cur]) {
        auto [nxt, toll] = x;
        if (cost[nxt][times] == INT_MAX)
          pq.push({c + toll, nxt, times});
        if (times >= 1 && cost[nxt][times - 1] == INT_MAX)
          pq.push({c + toll / 2, nxt, times - 1});
      }
    }

    return -1;
  }
};
