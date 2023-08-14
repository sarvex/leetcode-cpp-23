#include <set>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  std::unordered_map<std::string, std::string> Father;
  std::unordered_map<std::string, std::string> Owner;
  std::unordered_map<std::string, std::set<std::string>> Group;

public:
  std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>> &accounts) {
    for (int i = 0; i < accounts.size(); i++)
      for (int j = 1; j < accounts[i].size(); j++) {
        Father[accounts[i][j]] = accounts[i][j];
        Owner[accounts[i][j]] = accounts[i][0];
      }


    for (int i = 0; i < accounts.size(); i++) {
      for (int j = 2; j < accounts[i].size(); j++) {
        if (FindSet(accounts[i][j]) != FindSet(accounts[i][j - 1]))
          Union(accounts[i][j], accounts[i][j - 1]);
      }
    }

    for (int i = 0; i < accounts.size(); i++)
      for (int j = 1; j < accounts[i].size(); j++) {
        std::string parent = FindSet(accounts[i][j]);
        Group[parent].insert(accounts[i][j]);
      }

    std::vector<std::vector<std::string>> result;
    for (auto a: Group) {
      std::vector<std::string> temp;
      temp.push_back(Owner[a.first]);
      for (auto b: a.second)
        temp.push_back(b);
      result.push_back(temp);
    }
    return result;
  }

  std::string FindSet(std::string x) {
    if (x != Father[x])
      Father[x] = FindSet(Father[x]);
    return Father[x];
  }

  void Union(std::string x, std::string y) {
    x = Father[x];
    y = Father[y];
    if (x < y)
      Father[y] = x;
    else
      Father[x] = y;
  }
};
