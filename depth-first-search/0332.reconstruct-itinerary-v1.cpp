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

    return DFS("JFK");
  }

  std::vector<std::string> DFS(std::string start) {
    std::vector<std::vector<std::string>> paths;
    while (Map[start].size() > 0) {
      std::string nextStart = Map[start].front();
      Map[start].pop();
      paths.push_back(DFS(nextStart));
    }
    std::vector<std::string> ret({start});
    for (int i = paths.size() - 1; i >= 0; i--)
      for (auto t: paths[i])
        ret.push_back(t);
    return ret;
  }
};
