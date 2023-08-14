#include <string>
#include <unordered_set>
#include <vector>

class Solution {
public:
  long long distinctNames(std::vector<std::string> &ideas) {
    std::vector<std::unordered_set<std::string>> head2str(26);
    for (std::string &idea: ideas)
      head2str[idea[0] - 'a'].insert(idea.substr(1));

    long long ret = 0;
    for (int i = 0; i < 26; i++)
      for (int j = i + 1; j < 26; j++) {
        int dup = 0;
        for (std::string x: head2str[i])
          if (head2str[j].find(x) != head2str[j].end())
            dup++;
        long long a = head2str[i].size() - dup;
        long long b = head2str[j].size() - dup;
        ret += a * b * 2;
      }

    return ret;
  }
};
