#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  std::unordered_map<std::string, std::queue<std::string>> Map;

public:
  std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> tickets) {
    std::sort(tickets.begin(), tickets.end());
    for (auto ticket: tickets)
      Map[ticket[0]].push(ticket[1]);

    std::vector<std::string> path;
    DFS("JFK", path);
    std::reverse(path.begin(), path.end());
    return path;
  }

  void DFS(std::string start, std::vector<std::string> &path) {
    while (Map[start].size() > 0) {
      std::string nextStart = Map[start].front();
      Map[start].pop();
      DFS(nextStart, path);
    }
    path.push_back(start);
  }
};
