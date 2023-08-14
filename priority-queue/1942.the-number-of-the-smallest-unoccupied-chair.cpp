#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
  int smallestChair(std::vector<std::vector<int>> &times, int targetFriend) {
    std::priority_queue<int, std::vector<int>, std::greater<>> empty;
    for (int i = 0; i < times.size(); i++)
      empty.push(i);

    for (size_t i = 0; i < times.size(); i++)
      times[i].push_back(i);
    std::sort(times.begin(), times.end());

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> used;

    for (auto time: times) {
      int start = time[0];
      int end = time[1];
      int people = time[2];

      while (!used.empty() && used.top().first <= start) {
        empty.push(used.top().second);
        used.pop();
      }

      int chair = empty.top();
      empty.pop();
      if (people == targetFriend) return chair;

      used.push({end, chair});
    }

    return -1;
  }
};
