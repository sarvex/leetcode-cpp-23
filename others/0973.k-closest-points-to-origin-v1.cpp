#include <queue>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>> &points, int K) {
    std::priority_queue<std::pair<long long, int>> pq;
    for (size_t i = 0; i < points.size(); i++) {
      long long x1 = points[i][0];
      long long x2 = points[i][1];
      long long d = x1 * x1 + x2 * x2;
      pq.push({d, i});

      if (pq.size() > K)
        pq.pop();
    }

    std::vector<std::vector<int>> results;
    while (!pq.empty()) {
      int id = pq.top().second;
      results.push_back(points[id]);
      pq.pop();
    }
    return results;
  }
};
