#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  std::unordered_set<std::string> FailureSet;
  std::unordered_set<int> StoneSet;

public:
  bool canCross(std::vector<int> &stones) {
    for (auto a: stones)
      StoneSet.insert(a);
    return DFS(stones.back(), 1, 1);
  }

  bool DFS(int dest, int pos, int jump) {
    if (pos == dest)
      return true;

    if (StoneSet.find(pos) == StoneSet.end())
      return false;

    std::string temp = std::to_string(pos) + "#" + std::to_string(jump);
    if (FailureSet.find(temp) != FailureSet.end())
      return false;

    for (int k = std::max(1, jump - 1); k <= jump + 1; k++) {
      if (DFS(dest, pos + k, k))
        return true;
    }

    FailureSet.insert(temp);
    return false;
  }
};
