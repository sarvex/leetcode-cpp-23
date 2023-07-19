#include <algorithm>
#include <array>
#include <vector>

class Solution {
  std::array<int, 10> count;
  int b, n;

public:
  int maxHappyGroups(int batchSize, std::vector<int> &groups) {
    b = batchSize;
    n = groups.size();

    for (int i = 0; i < 10; i++)
      count[i] = 0;
    for (auto x: groups)
      count[x % batchSize]++;

    return dfs(count, 0, 0);
  }

  int dfs(std::array<int, 10> &count, int result, int i) {
    if (i == n)
      return 0;

    int bonus = (result % b == 0);
    int ret = 0;
    for (int j = 0; j < b; j++) {
      if (count[j] == 0) continue;
      count[j]--;
      ret = std::max(ret, dfs(count, (result + j) % b, i + 1));
      count[j]++;
    }

    return ret + bonus;
  }
};
