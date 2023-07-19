#include <string>
#include <vector>

class Solution {
  int k;
  std::string s;
  std::string ret;

public:
  std::string longestSubsequenceRepeatedK(std::string s, int k) {
    this->k = k;
    this->s = s;
    std::vector<int> count(26);
    for (auto ch: s)
      count[ch - 'a']++;
    std::string t;
    for (int i = 0; i < 26; i++) {
      if (count[i] >= k)
        t.push_back('a' + i);
    }

    std::string temp;
    dfs(t, temp);

    return ret;
  }

  void dfs(std::string &t, std::string &temp) {
    if (temp != "" && !checkOK(temp))
      return;

    if (temp.size() > ret.size() || (temp.size() == ret.size() && temp > ret))
      ret = temp;

    if (temp.size() == 7)
      return;

    for (auto ch: t) {
      temp.push_back(ch);
      dfs(t, temp);
      temp.pop_back();
    }
  }

  bool checkOK(std::string &temp) {
    int j = 0;
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != temp[j]) continue;
      j++;
      if (j == temp.size()) {
        j = 0;
        count++;
        if (count == k)
          return true;
      }
    }
    return false;
  }
};
