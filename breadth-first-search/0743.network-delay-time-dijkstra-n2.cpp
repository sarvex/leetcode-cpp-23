#include <limits>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution
{
public:
  int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k)
  {
    std::unordered_map<int, std::vector<std::pair<int, int>>> Map;
    for (auto t : times)
      Map[t[0]].push_back({t[1], t[2]});

    std::vector<int> dist(n + 1, std::numeric_limits<int>::max());
    std::vector<bool> seen(n + 1, 0);
    dist[k] = 0;

    for (int i = 1; i <= n; i++)
    {
      int minVal = std::numeric_limits<int>::max();
      int minNode = -1;
      for (int j = 1; j <= n; j++)
      {
        if (!seen[j] && dist[j] < minVal)
        {
          minVal = dist[j];
          minNode = j;
        }
      }
      if (minNode == -1)
        break;
      seen[minNode] = 1;
      for (auto [next, d] : Map[minNode])
        dist[next] = std::min(dist[next], dist[minNode] + d);
    }

    int ret = 0;
    for (int i = 1; i <= n; i++)
      ret = std::max(ret, dist[i]);

    return ret == std::numeric_limits<int>::max() ? -1 : ret;
  }
};
