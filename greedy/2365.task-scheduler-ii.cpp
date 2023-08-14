#include <unordered_map>
#include <vector>


class Solution {
public:
  long long taskSchedulerII(std::vector<int> &tasks, int space) {
    int n = tasks.size();
    std::unordered_map<int, long long> Map;
    long long cur = 0;
    for (int i = 0; i < n; i++) {
      if (Map.find(tasks[i]) != Map.end())
        cur = std::max(cur, Map[tasks[i]]);
      Map[tasks[i]] = cur + (long long) space + 1;
      cur++;
    }
    return cur;
  }
};
