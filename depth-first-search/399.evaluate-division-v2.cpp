#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
  std::unordered_map<std::string, std::vector<std::string>> next;
  std::unordered_map<std::string, double> value;
  std::unordered_map<std::string, int> visited;

public:
  std::vector<double> calcEquation(std::vector<std::pair<std::string, std::string>> equations, std::vector<double> &values, std::vector<std::pair<std::string, std::string>> queries) {
    for (int i = 0; i < equations.size(); i++) {
      next[equations[i].first].push_back(equations[i].second);
      value[equations[i].first + ":" + equations[i].second] = values[i];
      next[equations[i].second].push_back(equations[i].first);
      value[equations[i].second + ":" + equations[i].first] = 1.0 / values[i];
      visited[equations[i].first] = 0;
      visited[equations[i].second] = 0;
    }

    std::vector<double> results;

    for (int i = 0; i < queries.size(); i++) {
      for (auto a: visited)
        visited[a.first] = 0;
      results.push_back(DFS(queries[i].second, queries[i].first));
    }

    return results;
  }

  double DFS(std::string start, std::string end) {
    if (next.find(start) == next.end())
      return -1.0;

    if (start == end)
      return 1.0;

    for (auto b: next[start]) {
      if (visited[b] == 1) continue;

      visited[b] = 1;
      double temp = DFS(b, end);
      if (temp != -1.0)
        return value[b + ":" + start] * temp;
      visited[b] = 0;
    }

    return -1.0;
  }
};
