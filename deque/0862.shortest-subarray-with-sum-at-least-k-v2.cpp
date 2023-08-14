#include <algorithm>
#include <deque>
#include <limits>
#include <vector>

class Solution {
public:
  int shortestSubarray(std::vector<int> &nums, int k) {
    int n = nums.size();
    std::vector<long long> result(n + 1);
    for (int i = 0; i < nums.size(); i++)
      result[i + 1] = result[i] + nums[i];

    int ret = std::numeric_limits<int>::max();
    std::deque<int> dq;
    for (int i = 0; i <= n; i++) {
      while (!dq.empty() && result[dq.back()] >= result[i])
        dq.pop_back();

      while (!dq.empty() && result[i] - result[dq.front()] >= k) {
        ret = std::min(ret, i - dq.front());
        dq.pop_front();
      }

      dq.push_back(i);
    }

    if (ret == std::numeric_limits<int>::max()) return -1;
    else
      return ret;
  }
};
