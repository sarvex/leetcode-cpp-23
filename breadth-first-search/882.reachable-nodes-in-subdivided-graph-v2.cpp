#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution
{
  int dist[3000];
  int resolved[3000];

public:
  int reachableNodes(std::vector<std::vector<int>> &edges, int maxMoves, int n)
  {
    std::vector<std::pair<int, int>> adj[3000]; // {nextNode, weight}
    for (auto e : edges)
    {
      adj[e[0]].push_back({e[1], e[2] + 1});
      adj[e[1]].push_back({e[0], e[2] + 1});
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq; // {dist, nodeIdx}
    pq.push({0, 0});

    while (!pq.empty())
    {
      auto [d, cur] = pq.top();
      pq.pop();
      if (resolved[cur])
        continue;
      resolved[cur] = 1;
      dist[cur] = d;

      for (auto [next, weight] : adj[cur])
      {
        if (resolved[next])
          continue;
        if (d + weight <= maxMoves)
          pq.push({d + weight, next});
      }
    }

    int count = 0;
    for (auto e : edges)
    {
      int a = e[0], b = e[1];
      int sum = 0;
      if (resolved[a])
        sum += maxMoves - dist[a];
      if (resolved[b])
        sum += maxMoves - dist[b];
      count += std::min(sum, e[2]);
    }

    for (int i = 0; i < n; i++)
      if (resolved[i])
        count++;

    return count;
  }
};
