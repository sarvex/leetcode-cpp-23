#include <algorithm>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
  std::vector<int> Father;
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
  std::vector<std::pair<int, int>> e[100005];

  int numberOfGoodPaths(std::vector<int> &vals, std::vector<std::vector<int>> &edges) {
    int n = vals.size();
    Father.resize(n);
    for (int i = 0; i < n; i++)
      Father[i] = i;

    std::unordered_map<int, std::vector<int>> val2idx;
    for (int i = 0; i < n; i++)
      val2idx[vals[i]].push_back(i);

    for (auto &edge: edges) {
      int a = edge[0], b = edge[1];
      if (vals[a] < vals[b])
        std::swap(a, b);
      e[vals[a]].push_back({a, b});
    }

    int ret = 0;

    std::set<int> ValSet(vals.begin(), vals.end());
    for (int v: ValSet) {
      for (auto &[v, x]: e[v]) {
        if (FindFather(v) != FindFather(x))
          Union(v, x);
      }

      std::unordered_map<int, int> count;
      for (auto idx: val2idx[v]) {
        int root = FindFather(idx);
        count[root]++;
      }

      for (auto &[v, num]: count)
        ret += num * (num - 1) / 2;
    }

    return ret + n;
  }
};
