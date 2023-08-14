#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

class Solution {
  std::vector<std::vector<int>> next;
  std::vector<int> visited;
  int n;
  int ret = 0;

public:
  int numSquarefulPerms(std::vector<int> &A) {
    n = A.size();
    next.resize(n);
    visited.resize(n);
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (std::sqrt(A[i] + A[j]) == (int) std::sqrt(A[i] + A[j]))
          next[i].push_back(j);
      }
    for (int i = 0; i < n; i++) {
      if (i > 0 && A[i] == A[i - 1]) continue;
      visited[i] = 1;
      dfs(A, i, 1);
      visited[i] = 0;
    }
    return ret;
  }

  void dfs(std::vector<int> &A, int cur, int count) {
    if (count == n) {
      ret++;
      return;
    }

    int last = -1;
    for (auto i: next[cur]) {
      if (visited[i] == 1) continue;
      if (A[i] == last) continue;
      visited[i] = 1;
      last = A[i];
      dfs(A, i, count + 1);
      visited[i] = 0;
    }
  }
};
