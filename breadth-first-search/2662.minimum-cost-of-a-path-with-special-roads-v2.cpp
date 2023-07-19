#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int minimumCost(std::vector<int> &start, std::vector<int> &target, std::vector<std::vector<int>> &specialRoads) {
    std::priority_queue<std::pair<long long, long long>, std::vector<std::pair<long long, long long>>, std::greater<>> pq;// {dist to node, node id}
    pq.push({0, encode(start[0], start[1])});
    for (auto &road: specialRoads) {
      int x = road[2], y = road[3];
      pq.push({abs(start[0] - x) + abs(start[1] - y), encode(x, y)});
    }

    std::map<long long, long long> dist;
    long long ret = INT_MAX;
    while (!pq.empty()) {
      auto [len, id] = pq.top();
      pq.pop();
      if (dist.find(id) != dist.end()) continue;
      dist[id] = len;
      auto [x, y] = decode(id);

      ret = std::min(ret, len + abs(x - target[0]) + abs(y - target[1]));

      for (auto &road: specialRoads) {
        int x1 = road[0], y1 = road[1];
        int x2 = road[2], y2 = road[3];
        int cost = road[4];
        long long id2 = encode(x2, y2);

        if (dist.find(id2) == dist.end())
          pq.push({len + abs(x - x1) + abs(y - y1) + cost, id2});
      }
    }

    return ret;
  }

  long long encode(long long x, long long y) { return (x << 32) + y; }
  std::pair<long long, long long> decode(long long id) { return {id >> 32, id % (1long long << 32)}; }
};
