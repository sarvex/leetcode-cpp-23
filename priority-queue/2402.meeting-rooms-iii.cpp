#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  int mostBooked(int n, std::vector<std::vector<int>> &meetings) {
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> busy;
    std::priority_queue<int, std::vector<int>, std::greater<>> free;
    for (int i = 0; i < n; i++)
      free.push(i);


    sort(meetings.begin(), meetings.end());
    std::vector<long long> count(n);

    for (int i = 0; i < meetings.size(); i++) {
      long long start = meetings[i][0];
      long long end = meetings[i][1];

      while (!busy.empty() && busy.top().first <= start) {
        free.push(busy.top().second);
        busy.pop();
      }

      if (!free.empty()) {
        int idx = free.top();
        count[idx]++;
        free.pop();
        busy.push({end, idx});
      } else {
        auto [time, idx] = busy.top();
        count[idx] += 1;
        busy.pop();
        busy.push({time + end - start, idx});
      }
    }

    return max_element(count.begin(), count.end()) - count.begin();
  }
};
