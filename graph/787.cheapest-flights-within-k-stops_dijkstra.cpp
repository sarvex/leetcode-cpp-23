#include <algorithm>
#include <array>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src, int dst, int K) {
    std::vector<std::vector<std::pair<int, int>>> next(n);
    for (auto flight: flights) {
      int a = flight[0], b = flight[1], w = flight[2];
      next[a].push_back({b, w});
    }

    std::vector<std::vector<int>> cost(n, std::vector<int>(K + 2, std::numeric_limits<int>::max() / 2));
    std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, std::greater<>> pq;
    pq.push({0, src, 0});

    while (!pq.empty()) {
      auto [c, cur, stops] = pq.top();
      pq.pop();

      if (cur == dst) return c;
      if (stops == K + 1) continue;
      if (cost[cur][stops] < std::numeric_limits<int>::max() / 2) continue;
      cost[cur][stops] = c;

      for (auto ticket: next[cur]) {
        auto [nxt, price] = ticket;
        if (cost[nxt][stops + 1] < std::numeric_limits<int>::max() / 2) continue;
        pq.push({c + price, nxt, stops + 1});
      }
    }

    return -1;
  }
};
