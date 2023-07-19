#include <deque>
#include <limits>
#include <vector>

class Solution {
public:
  int findMaxValueOfEquation(std::vector<std::vector<int>> &points, int k) {
    int ret = std::numeric_limits<int>::max();
    std::deque<int> q;
    for (int i = 0; i < points.size(); i++) {
      while (q.size() > 0 && points[q.front()][0] < points[i][0] - k) {
        q.pop_front();
      }

      if (q.size() > 0) {
        ret = std::max(ret, -points[q.front()][0] + points[q.front()][1] + points[i][0] + points[i][1]);
      }

      while (q.size() > 0 && -points[q.back()][0] + points[q.back()][1] < -points[i][0] + points[i][1]) {
        q.pop_back();
      }

      q.push_back(i);
    }
    return ret;
  }
};
