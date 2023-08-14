#include <algorithm>
#include <unordered_set>
#include <vector>

class Solution {
  static bool cmp(std::vector<int> &a, std::vector<int> &b) {
    return a[2] < b[2];
  }
  std::vector<int> Father;

public:
  int findFather(int x) {
    if (Father[x] != x)
      Father[x] = findFather(Father[x]);
    return Father[x];
  }

  void Union(int x, int y) {
    x = Father[x];
    y = Father[y];
    if (x < y) Father[y] = x;
    else
      Father[x] = y;
  }

  int mst(int n, std::vector<std::vector<int>> &edges, int idx) {
    Father.resize(n);
    for (int i = 0; i < n; i++)
      Father[i] = i;

    std::unordered_set<int> temp;

    int result = 0;
    for (int i = 0; i < edges.size(); i++) {
      if (i == idx) continue;

      auto edge = edges[i];
      int a = edge[0];
      int b = edge[1];
      if (findFather(a) != findFather(b)) {
        Union(a, b);
        result += edge[2];
      }
    }

    for (int i = 0; i < n; i++) {
      if (findFather(i) != Father[1])
        return std::numeric_limits<int>::max();
    }

    return result;
  }


  std::vector<std::vector<int>> findCriticalAndPseudoCriticalEdges(int n, std::vector<std::vector<int>> &edges) {
    std::unordered_set<int> Set1;
    std::unordered_set<int> Set2;

    for (int i = 0; i < edges.size(); i++)
      edges[i].push_back(i);

    sort(edges.begin(), edges.end(), cmp);

    int minWt = mst(n, edges, -1);

    for (int i = 0; i < edges.size(); i++) {
      int wt = mst(n, edges, i);
      if (wt > minWt) Set1.insert(edges[i][3]);
    }

    for (int i = 0; i < edges.size(); i++) {
      auto edge = edges[i];

      edges.insert(edges.begin(), edge);

      int wt = mst(n, edges, -1);
      if (wt == minWt) Set2.insert(edge[3]);

      edges.erase(edges.begin());
    }

    std::vector<int> rets1(Set1.begin(), Set1.end());

    std::vector<int> rets2;
    for (int x: Set2) {
      if (Set1.find(x) == Set1.end())
        rets2.push_back(x);
    }

    return {rets1, rets2};
  }
};
