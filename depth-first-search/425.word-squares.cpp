#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  std::vector<std::vector<std::string>> rets;
  std::unordered_map<std::string, std::vector<std::string>> Map;
  int n;

public:
  std::vector<std::vector<std::string>> wordSquares(std::vector<std::string> &words) {
    this->n = words[0].size();
    for (auto &word: words) {
      for (int i = 0; i < n; i++)
        Map[word.substr(0, i)].push_back(word);
    }
    std::vector<std::string> ret;
    dfs(0, ret, words);
    return rets;
  }

  void dfs(int row, std::vector<std::string> &ret, std::vector<std::string> &words) {
    if (row == n) {
      rets.push_back(ret);
      return;
    }

    std::string prefix;
    for (int i = 0; i < row; i++)
      prefix.push_back(ret[i][row]);

    for (auto &word: Map[prefix]) {
      ret.push_back(word);
      dfs(row + 1, ret, words);
      ret.pop_back();
    }
  }
};
