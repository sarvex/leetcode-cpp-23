#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
  int m, n;
  int match[8][8];

public:
  int maxCompatibilitySum(std::vector<std::vector<int>> &students, std::vector<std::vector<int>> &mentors) {
    m = students.size();
    n = students[0].size();

    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++) {
        int count = 0;
        for (int k = 0; k < n; k++)
          count += (students[i][k] == mentors[j][k]);
        match[i][j] = n - count;
      }

    std::priority_queue<pair<std::int, int>, std::vector<pair<std::int, int>>, std::greater<>> pq;
    pq.push({0, 0});

    std::vector<int> dp(1 << m, -1);

    while (!pq.empty()) {
      auto [cost, state] = pq.top();
      pq.pop();

      if (dp[state] != -1) continue;
      dp[state] = cost;
      if (state == (1 << m) - 1)
        return m * n - cost;

      int j = __builtin_popcount(state);
      for (int i = 0; i < m; i++) {
        if (((state >> i) & 1) == 1) continue;
        if (dp[state + (1 << i)] != -1) continue;
        pq.push({cost + match[i][j], state + (1 << i)});
      }
    }

    return -1;
  }
};
