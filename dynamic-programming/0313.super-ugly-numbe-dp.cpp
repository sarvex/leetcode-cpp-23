#include <algorithm>
#include <vector>

class Solution {
public:
  int nthSuperUglyNumber(int n, std::vector<int> &primes) {
    int k = primes.size();
    std::vector<int> p(k, 0);

    std::vector<int> rets({1});

    for (int i = 0; i < n - 1; i++) {
      int nxt = std::numeric_limits<int>::max();
      for (int j = 0; j < k; j++)
        nxt = std::min(nxt, primes[j] * rets[p[j]]);
      for (int j = 0; j < k; j++) {
        if (nxt == primes[j] * rets[p[j]])
          p[j]++;
      }
      rets.push_back(nxt);
    }

    return rets.back();
  }
};
