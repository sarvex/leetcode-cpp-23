#include <algorithm>
#include <utility>
#include <vector>

class Solution {
  std::vector<std::pair<int, long long>> children[100005];
  long long memo[100005][2];

public:
  long long maxScore(std::vector<std::vector<int>> &edges) {
    int n = edges.size();
    int root = -1;
    for (int i = 0; i < n; i++) {
      if (edges[i][0] == -1) {
        root = i;
        continue;
      }
      int par = edges[i][0];
      int weight = edges[i][1];
      children[par].push_back({i, weight});
    }

    return dfs(root, 0);
  }

  long long dfs(int node, int status) {
    if (memo[node][status] != 0)
      return memo[node][status];

    if (status == 0) {
      long long sum = 0;
      for (auto &[child, weight]: children[node])
        sum += dfs(child, 0);

      long long maxSum = sum;
      for (auto &[child, weight]: children[node])
        maxSum = std::max(maxSum, sum - dfs(child, 0) + dfs(child, 1) + weight);

      memo[node][0] = maxSum;
      return maxSum;
    } else {
      long long sum = 0;
      for (auto &[child, weight]: children[node])
        sum += dfs(child, 0);
      memo[node][1] = sum;
      return sum;
    }
  }
};
