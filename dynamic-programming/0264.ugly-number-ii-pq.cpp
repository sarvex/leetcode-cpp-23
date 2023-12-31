#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

class Solution {
public:
  int nthUglyNumber(int n) {
    std::priority_queue<long, std::vector<long>, std::greater<>> pq;
    pq.push(1);

    for (int t = 0; t < n; t++) {
      long cur = pq.top();
      pq.pop();
      if (t == n - 1) return cur;
      while (!pq.empty() && pq.top() == cur)
        pq.pop();

      if (cur * 2 < std::numeric_limits<int>::max()) pq.push(cur * 2);
      if (cur * 3 < std::numeric_limits<int>::max()) pq.push(cur * 3);
      if (cur * 5 < std::numeric_limits<int>::max()) pq.push(cur * 5);
    }

    return -1;
  }
};
