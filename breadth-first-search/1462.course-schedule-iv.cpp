#include <queue>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<bool> checkIfPrerequisite(int n, std::vector<std::vector<int>> &prerequisites, std::vector<std::vector<int>> &queries) {
    std::vector<std::unordered_set<int>> next(n);
    std::vector<int> inDegree(n, 0);
    std::vector<std::unordered_set<int>> preSet(n);

    for (auto edge: prerequisites) {
      next[edge[0]].insert(edge[1]);
      inDegree[edge[1]] += 1;
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++) {
      preSet[i].insert(i);
      if (inDegree[i] == 0)
        q.push(i);
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next: next[cur]) {
        for (auto x: preSet[cur])
          preSet[next].insert(x);

        inDegree[next] -= 1;
        if (inDegree[next] == 0)
          q.push(next);
      }
    }

    std::vector<bool> rets;
    for (auto query: queries) {
      rets.push_back(preSet[query[1]].find(query[0]) != preSet[query[1]].end());
    }
    return rets;
  }
};
