#include <algorithm>
#include <queue>
#include <vector>

class Solution {
  std::vector<int> next[100];

public:
  int maximumDetonation(std::vector<std::vector<int>> &bombs) {
    int n = bombs.size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        long long dx = bombs[i][0] - bombs[j][0];
        long long dy = bombs[i][1] - bombs[j][1];
        long long r = bombs[i][2];
        if (dx * dx + dy * dy <= r * r)
          next[i].push_back(j);
      }

    int ret = 0;
    for (int s = 0; s < n; s++) {
      std::queue<int> q;
      q.push(s);
      std::vector<int> visited(n);
      visited[s] = 1;
      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i: next[cur]) {
          if (visited[i]) continue;
          q.push(i);
          visited[i] = 1;
        }
      }
      int count = 0;
      for (int i = 0; i < n; i++)
        count += visited[i];
      ret = std::max(count, ret);
    }
    return ret;
  }
};
