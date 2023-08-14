#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  int visited[1000];

public:
  int minCostConnectPoints(std::vector<std::vector<int>> &points) {
    int n = points.size();

    std::vector<std::vector<std::pair<int, int>>> edges(n);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) {
        int dis = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        edges[i].push_back({dis, j});
        edges[j].push_back({dis, i});
      }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq(edges[0].begin(), edges[0].end());
    visited[0] = 1;
    int result = 0;

    for (int k = 0; k < n - 1; k++) {
      while (!pq.empty() && visited[pq.top().second] == 1)
        pq.pop();
      int next = pq.top().second;
      visited[next] = 1;
      result += pq.top().first;
      pq.pop();

      for (auto edge: edges[next])
        pq.push(edge);
    }

    return result;
  }
};
