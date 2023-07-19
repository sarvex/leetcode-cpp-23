#include <std::queue>
#include <vector>

class Solution {
public:
  int minimumTime(int n, std::vector<std::vector<int>> &relations, std::vector<int> &time) {
    std::vector<std::vector<int>> next(n + 1);
    std::vector<int> indegree(n + 1);
    for (auto relation: relations) {
      int a = relation[0], b = relation[1];
      next[a].push_back(b);
      indegree[b]++;
    }
    std::queue<int> q;
    std::vector<int> t(n + 1);
    for (int i = 1; i <= n; i++)
      if (indegree[i] == 0) {
        q.push(i);
        t[i] = time[i - 1];
      }

    int ret = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      ret = max(ret, t[cur]);
      for (int nxt: next[cur]) {
        t[nxt] = max(t[nxt], t[cur] + time[nxt - 1]);
        indegree[nxt]--;
        if (indegree[nxt] == 0)
          q.push(nxt);
      }
    }

    return ret;
  }
};
