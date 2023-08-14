#include <unordered_map>
#include <vector>

class Solution {
  std::unordered_map<long long, long long> Map;
  std::vector<std::vector<int>> children;

public:
  int countHighestScoreNodes(std::vector<int> &parents) {
    int n = parents.size();
    children.resize(n);
    for (int i = 1; i < n; i++) {
      children[parents[i]].push_back(i);
    }

    dfs(0);

    long long maxVal = -1;
    long long num = 0;
    for (auto x: Map) {
      if (x.first > maxVal) {
        maxVal = x.first;
        num = x.second;
      }
    }

    return num;
  }

  int dfs(int node) {
    int n = children.size();
    std::vector<int> sub;
    int sub_total = 0;
    for (auto child: children[node]) {
      sub.push_back(dfs(child));
      sub_total += sub.back();
    }
    int U = n - (sub_total + 1);
    long long ret = 1;
    if (U != 0) ret *= U;
    for (auto x: sub)
      if (x != 0) ret *= x;
    Map[ret]++;

    return sub_total + 1;
  }
};
