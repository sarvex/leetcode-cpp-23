#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  std::vector<int> path;       // path[i] is the i-th node idx along the dfs path
  std::vector<int> records[51];// records[i] contains the depths of all the nodes whose num = i
  std::vector<int> rets;
  std::vector<int> next[100000];
  int visited[100000];
  std::vector<int> nums;

public:
  std::vector<int> getCoprimes(std::vector<int> &nums, std::vector<std::vector<int>> &edges) {
    this->nums = nums;
    int n = nums.size();
    rets.resize(n);

    for (auto e: edges) {
      next[e[0]].push_back(e[1]);
      next[e[1]].push_back(e[0]);
    }

    visited[0] = 1;
    dfs(0, 0);
    return rets;
  }

  void dfs(int curIdx, int depth) {
    int i = -1;
    for (int d = 1; d <= 50; d++) {
      if (records[d].size() > 0 && std::gcd(d, nums[curIdx]) == 1) {
        i = std::max(i, records[d].back());
      }
    }
    rets[curIdx] = (i == -1) ? -1 : path[i];

    path.push_back(curIdx);
    records[nums[curIdx]].push_back(depth);

    for (int nextIdx: next[curIdx]) {
      if (visited[nextIdx]) continue;
      visited[nextIdx] = 1;
      dfs(nextIdx, depth + 1);
      visited[nextIdx] = 0;
    }

    path.pop_back();
    records[nums[curIdx]].pop_back();
  }
};
