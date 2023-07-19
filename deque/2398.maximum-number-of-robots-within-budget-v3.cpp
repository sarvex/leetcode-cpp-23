#include <deque>
#include <utility>
#include <vector>

class Solution {
public:
  int maximumRobots(std::vector<int> &chargeTimes, std::vector<int> &runningCosts, long long budget) {
    std::vector<std::pair<long long, long long>> robots;
    int n = chargeTimes.size();

    long long left = 0, right = n;
    while (left < right) {
      long long mid = right - (right - left) / 2;
      if (isOK(mid, chargeTimes, runningCosts, budget))
        left = mid;
      else
        right = mid - 1;
    }
    return left;
  }

  bool isOK(long long k, std::vector<int> &chargeTimes, std::vector<int> &runningCosts, long long budget) {
    long long n = chargeTimes.size();
    long long sum = 0;
    std::deque<int> dq;

    for (int i = 0; i < n; i++) {
      sum += runningCosts[i];
      while (!dq.empty() && chargeTimes[dq.back()] <= chargeTimes[i])
        dq.pop_back();
      dq.push_back(i);
      while (!dq.empty() && dq.front() <= i - k)
        dq.pop_front();

      if (i >= k - 1) {
        long long ret = chargeTimes[dq.front()] + (long long) k * sum;
        if (ret <= budget) return true;
        sum -= runningCosts[i - k + 1];
      }
    }

    return false;
  }
};
