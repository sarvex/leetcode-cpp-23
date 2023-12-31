#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  std::unordered_map<char, std::string> Map1;
  std::unordered_map<std::string, char> Map2;
  bool visited[20][20];

public:
  bool wordPatternMatch(std::string pattern, std::string s) {
    return dfs(0, 0, pattern, s);
  }

  bool dfs(int x, int y, std::string &pattern, std::string &s) {
    if (x == pattern.size()) return y == s.size();

    char ch = pattern[x];
    if (Map1.find(ch) != Map1.end()) {
      std::string t = Map1[ch];
      if (y + t.size() > s.size()) return false;
      if (s.substr(y, t.size()) != t) return false;
      return dfs(x + 1, y + t.size(), pattern, s);
    } else {
      for (int i = y; i < s.size(); i++) {
        std::string t = s.substr(y, i - y + 1);
        if (Map2.find(t) != Map2.end()) continue;
        Map1[ch] = t;
        Map2[t] = ch;
        if (dfs(x + 1, y + t.size(), pattern, s))
          return true;
        Map1.erase(ch);
        Map2.erase(t);
      }
      return false;
    }
  }
};
