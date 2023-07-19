#include <algorithm>
#include <numeric>
#include <queue>
#include <vector>

class Solution {
public:
  int componentValue(std::vector<int> &nums, std::vector<std::vector<int>> &edges) {
    int n = nums.size();
    if (n == 1) return 0;

    std::vector<std::vector<int>> next(n);
    std::vector<int> indegree(n);

    for (auto &edge: edges) {
      int a = edge[0], b = edge[1];
      next[a].push_back(b);
      next[b].push_back(a);
      indegree[b]++;
      indegree[a]++;
    }

    int total = std::accumulate(nums.begin(), nums.end(), 0);

    std::vector<int> sums;
    for (int s = 1; s * s <= total; s++) {
      if (total % s != 0) continue;
      sums.push_back(s);
      sums.push_back(total / s);
    }
    std::sort(sums.begin(), sums.end());

    for (auto s: sums) {
      std::vector<int> in = indegree;
      std::queue<int> q;
      std::vector<int> visited(n, 0);
      std::vector<int> sum = nums;

      for (int i = 0; i < n; i++)
        if (in[i] == 1) {
          q.push(i);
          visited[i] = 1;
        }

      int flag = true;

      while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (sum[cur] > s) {
          flag = false;
          break;
        } else if (sum[cur] == s)
          sum[cur] = 0;

        for (int nxt: next[cur]) {
          if (visited[nxt]) continue;
          sum[nxt] += sum[cur];
          in[nxt]--;

          if (in[nxt] == 1) {
            visited[nxt] = 1;
            q.push(nxt);
          }
        }
      }

      if (flag) return total / s - 1;
    }

    return 0;
  }
};
