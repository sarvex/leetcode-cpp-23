#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int eatenApples(std::vector<int> &apples, std::vector<int> &days) {
    int count = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    size_t i = 0;
    while (i < apples.size() || !pq.empty()) {
      while (!pq.empty() && pq.top().first <= i)
        pq.pop();
      if (i < apples.size() && apples[i] > 0)
        pq.push({i + days[i], apples[i]});
      if (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        count++;
        if (x.second >= 2)
          pq.push({x.first, x.second - 1});
      }
      i++;
    }
    return count;
  }
};
