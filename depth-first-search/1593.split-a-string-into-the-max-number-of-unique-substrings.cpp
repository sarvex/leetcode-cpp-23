#include <string>
#include <unordered_set>

class Solution {
  int ret = 0;
  std::unordered_set<std::string> Set;

public:
  int maxUniqueSplit(std::string s) {
    int n = s.size();
    dfs(s, 0, 0);
    return ret;
  }
  void dfs(std::string &s, int cur, int len) {
    if (cur == s.size()) {
      ret = std::max(ret, len);
      return;
    }
    if (s.size() - cur + len <= ret)
      return;

    for (int i = cur; i < s.size(); i++) {
      if (Set.find(s.substr(cur, i - cur + 1)) == Set.end()) {
        Set.insert(s.substr(cur, i - cur + 1));
        dfs(s, i + 1, len + 1);
        Set.erase(s.substr(cur, i - cur + 1));
      }
    }
  }
};
