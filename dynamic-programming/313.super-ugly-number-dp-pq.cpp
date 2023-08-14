#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int nthSuperUglyNumber(int n, std::vector<int> &primes) {
    int k = primes.size();

    std::vector<long long> rets({1});
    std::vector<long long> p(k, 0);

    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> pq;
    for (int i = 0; i < k; i++)
      pq.push({rets[p[i]] * primes[i], i});

    for (int t = 0; t < n - 1; t++) {
      long long cur = pq.top().first;
      rets.push_back(cur);

      while (!pq.empty() && cur == pq.top().first) {
        int i = pq.top().second;
        pq.pop();

        p[i]++;
        pq.push({rets[p[i]] * primes[i], i});
      }
    }

    return rets.back();
  }
};
