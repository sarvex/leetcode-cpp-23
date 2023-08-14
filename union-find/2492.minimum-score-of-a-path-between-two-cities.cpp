#include <algorithm>
#include <vector>

class Solution {
  int Father[100005];
  int FindFather(int x) {
    if (Father[x] != x)
      Father[x] = FindFather(Father[x]);
    return Father[x];
  }

  void Union(int x, int y) {
    x = Father[x];
    y = Father[y];
    if (x < y) Father[y] = x;
    else
      Father[x] = y;
  }

public:
  int minScore(int n, std::vector<std::vector<int>> &roads) {
    for (int i = 1; i <= n; i++)
      Father[i] = i;

    for (auto road: roads) {
      int a = road[0], b = road[1], d = road[2];
      if (FindFather(a) != FindFather(b))
        Union(a, b);
    }

    int ret = std::numeric_limits<int>::max();
    for (auto road: roads) {
      int a = road[0], b = road[1], d = road[2];
      if (FindFather(a) == FindFather(1))
        ret = std::min(ret, d);
    }

    return ret;
  }
};
