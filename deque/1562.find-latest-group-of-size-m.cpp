#include <algorithm>
#include <deque>
#include <limits>
#include <vector>

class Solution {
public:
  int findLatestStep(std::vector<int> &arr, int m) {
    int n = arr.size();
    arr.insert(arr.begin(), 0);
    int ret = -1;

    if (n == m) return n;
    std::vector<int> day(n + 1);
    for (int i = 1; i <= n; i++)
      day[arr[i]] = i;

    std::deque<int> dq;

    for (int i = 1; i <= n; i++) {
      while (dq.size() > 0 && day[dq.back()] < day[i])
        dq.pop_back();
      while (dq.size() > 0 && i - dq.front() >= m)
        dq.pop_front();
      dq.push_back(i);

      if (i < m) continue;

      int maxDay = day[dq.front()];

      int left = std::numeric_limits<int>::max(), right = std::numeric_limits<int>::max();
      if (i - m >= 1) left = day[i - m];
      if (i + 1 <= n) right = day[i + 1];

      if (maxDay < left && maxDay < right)
        ret = std::max(ret, std::min(left, right) - 1);
    }
    return ret;
  }
};
