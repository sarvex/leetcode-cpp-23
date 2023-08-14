#include <set>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution {
  std::unordered_set<int> stoneSet;
  std::set<std::pair<int, int>> failed;

public:
  bool canCross(std::vector<int> &stones) {
    for (auto x: stones)
      stoneSet.insert(x);
    return dfs(stones, 0, 0);
  }

  bool dfs(std::vector<int> &stones, int pos, int jump) {
    if (pos == stones.back()) return true;
    if (stoneSet.find(pos) == stoneSet.end()) return false;
    if (failed.find({pos, jump}) != failed.end()) return false;

    if (jump > 1 && dfs(stones, pos + jump - 1, jump - 1))
      return true;
    if (jump > 0 && dfs(stones, pos + jump, jump))
      return true;
    if (dfs(stones, pos + jump + 1, jump + 1))
      return true;

    failed.insert({pos, jump});
    return false;
  }
};
