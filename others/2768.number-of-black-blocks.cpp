#include <unordered_map>
#include <vector>

class Solution {
  int n;

public:
  long long encode(long long x, long long y) {
    return x * n + y;
  }

  std::vector<long long> countBlackBlocks(int m, int n, std::vector<std::vector<int>> &coordinates) {
    std::unordered_map<long long, int> Map;
    this->n = n;

    int count = 0;
    for (auto &c: coordinates) {
      int x = c[0], y = c[1];
      for (int i = x - 1; i <= x; i++)
        for (int j = y - 1; j <= y; j++) {
          if (i >= 0 && i < m - 1 && j >= 0 && j < n - 1)
            Map[encode(i, j)] += 1;
        }
    }

    std::vector<long long> rets(5);
    for (auto [k, v]: Map)
      rets[v] += 1;

    rets[0] = long long(m - 1) * long long(n - 1) - rets[1] - rets[2] - rets[3] - rets[4];

    return rets;
  }
};
