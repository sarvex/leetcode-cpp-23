#include <algorithm>
#include <limits>
#include <map>
#include <vector>

class Solution {
public:
  int shortestSubarray(std::vector<int> &A, int K) {
    int N = A.size();

    A.insert(A.begin(), 0);

    std::vector<int> Sum(N + 1, 0);
    std::map<int, int> Map;

    Map[0] = 0;
    int ret = std::numeric_limits<int>::max();

    for (int i = 1; i <= N; i++) {
      Sum[i] = Sum[i - 1] + A[i];

      int num = Sum[i] - K;

      auto it = Map.upper_bound(num);
      if (it != Map.begin()) {
        it = prev(it, 1);
        ret = std::min(ret, i - it->second);
      }

      Map[Sum[i]] = i;
      while (Map.rbegin()->first != Sum[i])
        Map.erase(Map.rbegin()->first);
    }

    if (ret == std::numeric_limits<int>::max())
      return -1;
    else
      return ret;
  }
};
