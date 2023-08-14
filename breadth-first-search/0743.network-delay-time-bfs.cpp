#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
  int networkDelayTime(std::vector<std::vector<int>> &times, int N, int K) {
    std::unordered_map<int, int> EarliestTime;// node->earliestTime;
    for (int i = 1; i <= N; i++)
      EarliestTime[i] = std::numeric_limits<int>::max();
    EarliestTime[K] = 0;

    std::unordered_map<int, std::vector<std::pair<int, int>>> next;
    for (auto time: times) {
      next[time[0]].push_back({time[1], time[2]});
    }

    std::queue<std::pair<int, int>> q;// {node,earliestTime}
    q.push({K, 0});

    while (!q.empty()) {
      int curNode = q.front().first;
      int curTime = q.front().second;
      q.pop();

      if (curTime > EarliestTime[curNode])
        continue;

      for (auto t: next[curNode]) {
        int nextNode = t.first;
        int weight = t.second;

        if (EarliestTime[nextNode] <= EarliestTime[curNode] + weight)
          continue;
        EarliestTime[nextNode] = EarliestTime[curNode] + weight;
        q.push({nextNode, EarliestTime[nextNode]});
      }
    }

    int result = 0;
    for (int i = 1; i <= N; i++)
      result = std::max(result, EarliestTime[i]);
    if (result == std::numeric_limits<int>::max())
      return -1;
    else
      return result;
  }
};
