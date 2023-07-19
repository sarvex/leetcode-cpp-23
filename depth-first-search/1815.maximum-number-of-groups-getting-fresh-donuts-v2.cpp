#include <unordered_map>
#include <vector>

class Solution {
  int b, n;
  std::unordered_map<long long, int> memo;

public:
  int maxHappyGroups(int batchSize, std::vector<int> &groups) {
    b = batchSize;
    n = groups.size();

    std::vector<int> count(b);
    for (auto x: groups)
      count[x % batchSize]++;

    long long state = 0;
    for (int i = 0; i < b; i++) {
      state += (long long) count[i] << (i * 5);
    }

    return dfs(state, 0, 0);
  }

  int dfs(long long state, int presum, int i) {
    if (i == n) return 0;
    if (memo.find(state) != memo.end())
      return memo[state];

    int bonus = (presum % b == 0);
    int ret = 0;
    for (int j = 0; j < b; j++) {
      if ((state >> (j * 5)) % 32 == 0) continue;
      ret = std::max(ret, dfs(state - (1ll << (j * 5)), (presum + j) % b, i + 1));
    }
    memo[state] = ret + bonus;
    return ret + bonus;
  }
};
