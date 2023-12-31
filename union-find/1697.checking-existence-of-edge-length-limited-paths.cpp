#include <algorithm>
#include <vector>

class Solution {
  int Father[100005];

  static bool cmp(std::vector<int> &a, std::vector<int> &b) {
    return a[2] < b[2];
  }

public:
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

  std::vector<bool> distanceLimitedPathsExist(int n, std::vector<std::vector<int>> &edgeList, std::vector<std::vector<int>> &queries) {
    for (int i = 0; i < n; i++)
      Father[i] = i;

    for (int i = 0; i < queries.size(); i++)
      queries[i].push_back(i);

    std::sort(queries.begin(), queries.end(), cmp);
    std::sort(edgeList.begin(), edgeList.end(), cmp);

    size_t i = 0;
    std::vector<bool> ret(queries.size(), 0);
    for (auto &q: queries) {
      while (i < edgeList.size() && edgeList[i][2] < q[2]) {
        int a = edgeList[i][0];
        int b = edgeList[i][1];
        if (FindFather(a) != FindFather(b))
          Union(a, b);
        i++;
      }
      int idx = q[3];
      ret[idx] = (FindFather(q[0]) == FindFather(q[1]));
    }
    return ret;
  }
};
