#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::string> findAllRecipes(std::vector<std::string> &recipes, std::vector<std::vector<std::string>> &ingredients, std::vector<std::string> &supplies) {
    std::queue<std::string> q;
    for (auto x: supplies)
      q.push(x);

    std::unordered_map<std::string, int> indegree;
    std::unordered_map<std::string, std::vector<std::string>> next;
    std::unordered_set<std::string> wanted(recipes.begin(), recipes.end());

    for (int i = 0; i < recipes.size(); i++)
      for (int j = 0; j < ingredients[i].size(); j++) {
        next[ingredients[i][j]].push_back(recipes[i]);
        indegree[recipes[i]] += 1;
      }

    std::vector<std::string> rets;
    while (!q.empty()) {
      std::string cur = q.front();
      q.pop();
      if (wanted.find(cur) != wanted.end())
        rets.push_back(cur);
      for (auto x: next[cur]) {
        indegree[x] -= 1;
        if (indegree[x] == 0)
          q.push(x);
      }
    }

    return rets;
  }
};
