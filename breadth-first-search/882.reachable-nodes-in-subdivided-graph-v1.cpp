#include <algorithm>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution
{
public:
  int reachableNodes(std::vector<std::vector<int>> &edges, int maxMoves, int n)
  {
    std::unordered_map<int, std::vector<std::pair<int, int>>> Map;
    for (auto e : edges)
    {
      Map[e[0]].push_back({e[1], e[2]});
      Map[e[1]].push_back({e[0], e[2]});
    }
    std::unordered_map<int, std::unordered_map<int, int>> edgeVisitedNodes;

    priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    std::vector<int> resolved(n);

    while (!pq.empty())
    {
      auto [d, cur] = pq.top();
      pq.pop();

      if (resolved[cur])
        continue;
      resolved[cur] = 1;

      for (auto [next, cnt] : Map[cur])
      {
        // if (resolved[next]) continue;  // Do NOT add this line.
        edgeVisitedNodes[cur][next] = std::min(maxMoves - d, cnt);
        if (maxMoves >= d + cnt + 1)
          pq.push({d + cnt + 1, next});
      }
    }

    int count = 0;
    for (auto e : edges)
    {
      int a = e[0], b = e[1], cnt = e[2];
      count += std::min(cnt, edgeVisitedNodes[a][b] + edgeVisitedNodes[b][a]);
    }
    for (int i = 0; i < n; i++)
      if (resolved[i])
        count++;
    return count;
  }
};
