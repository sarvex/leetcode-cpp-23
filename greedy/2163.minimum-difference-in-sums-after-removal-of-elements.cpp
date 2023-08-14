#include <algorithm>
#include <limits>
#include <queue>
#include <vector>

class Solution {
public:
  long long minimumDifference(std::vector<int> &nums) {
    int n = nums.size() / 3;

    std::vector<long long> leftMin(3 * n);
    std::priority_queue<int> pq;
    long long sum = 0;
    for (int i = 0; i < 3 * n; i++) {
      pq.push(nums[i]);
      sum += nums[i];
      if (pq.size() > n) {
        sum -= pq.top();
        pq.pop();
      }
      leftMin[i] = sum;
    }

    std::vector<long long> rightMax(3 * n);
    std::priority_queue<int, std::vector<int>, std::greater<>> pq2;
    sum = 0;
    for (int i = 3 * n - 1; i >= 0; i--) {
      pq2.push(nums[i]);
      sum += nums[i];
      if (pq2.size() > n) {
        sum -= pq2.top();
        pq2.pop();
      }
      rightMax[i] = sum;
    }

    long long ret = std::numeric_limits<long long>::max();
    for (int i = n - 1; i < 2 * n; i++)
      ret = std::min(ret, leftMin[i] - rightMax[i + 1]);

    return ret;
  }
};
