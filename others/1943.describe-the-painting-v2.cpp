#include <map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<long long>> splitPainting(std::vector<std::vector<int>> &segments) {
    std::map<long long, long long> diffPairs;

    for (auto seg: segments) {
      diffPairs[seg[0]] += seg[2];
      diffPairs[seg[1]] -= seg[2];
    }

    long long start = -1, end = -1;
    long long sum = 0;
    std::vector<std::vector<long long>> rets;

    for (auto x: diffPairs) {
      auto [pos, diff] = x;

      if (start == -1)
        start = pos;
      else {
        end = pos;
        rets.push_back({start, end, sum});
        start = end;
      }

      sum += diff;

      if (sum == 0)
        start = -1;
    }

    return rets;
  }
};
