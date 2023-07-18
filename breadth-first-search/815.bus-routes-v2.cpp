#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
public:
  int numBusesToDestination(std::vector<std::vector<int>> &routes, int S, int T)
  {
    if (S == T)
      return 0;

    std::unordered_map<int, std::vector<int>> stop2bus;
    for (int i = 0; i < routes.size(); i++)
    {
      for (auto j : routes[i])
        stop2bus[j].push_back(i);
    }

    std::unordered_set<int> visitedStop;
    std::unordered_set<int> visitedBus;

    std::queue<int> q;
    q.push(S);
    visitedStop.insert(S);
    int step = -1;

    while (!q.empty())
    {
      step += 1;

      int len = q.size();
      while (len--)
      {
        int curStop = q.front();
        q.pop();

        for (auto bus : stop2bus[curStop])
        {
          if (visitedBus.find(bus) != visitedBus.end())
            continue;
          visitedBus.insert(bus);

          for (auto nextStop : routes[bus])
          {
            if (visitedStop.find(nextStop) != visitedStop.end())
              continue;
            if (nextStop == T)
              return step + 1;

            q.push(nextStop);
            visitedStop.insert(nextStop);
          }
        }
      }
    }

    return -1;
  }
};
