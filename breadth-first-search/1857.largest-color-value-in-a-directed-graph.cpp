#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

class Solution {
  int inD[100000];
  std::vector<int> next[100000];

public:
  int largestPathValue(std::string colors, std::vector<std::vector<int>> &edges) {
    int ans = 1;
    for (auto edge: edges) {
      int a = edge[0], b = edge[1];
      next[a].push_back(b);
      inD[b]++;
    }

    std::unordered_set<char> Set(colors.begin(), colors.end());
    for (char ch = 'a'; ch <= 'z'; ch++) {
      if (Set.find(ch) == Set.end()) continue;
      int t = helper(ch - 'a', colors, edges);
      if (t == -1) return -1;
      ans = std::max(ans, t);
    }
    return ans;
  }

  int helper(int k, std::string colors, std::vector<std::vector<int>> &edges) {
    int n = colors.size();
    std::vector<int> count(n, 0);
    std::vector<int> in(n, 0);
    for (int i = 0; i < n; i++)
      in[i] = inD[i];

    int nodes = 0;
    std::queue<int> q;
    for (int i = 0; i < n; i++) {
      if (in[i] == 0) {
        nodes++;
        if (colors[i] - 'a' == k) count[i]++;
        q.push({i});
      }
    }

    int ret = 0;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      for (auto p: next[cur]) {
        count[p] = std::max(count[p], count[cur] + (colors[p] - 'a' == k));
        ret = std::max(ret, count[p]);
        in[p]--;
        if (in[p] == 0) {
          nodes++;
          q.push(p);
        }
      }
    }

    if (nodes != n) return -1;
    return ret;
  }
};
