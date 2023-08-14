#include <algorithm>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
  long long maxScore(std::vector<int> &nums1, std::vector<int> &nums2, int k) {
    int n = nums1.size();
    std::vector<std::pair<long long, long long>> arr;
    for (int i = 0; i < n; i++)
      arr.push_back({nums2[i], nums1[i]});

    sort(arr.rbegin(), arr.rend());

    std::priority_queue<long long, std::vector<long long>, std::greater<>> pq;
    long long minVal = std::numeric_limits<int>::max();
    long long sum = 0;
    long long ret = 0;
    for (int i = 0; i < n; i++) {
      minVal = arr[i].first;
      sum += arr[i].second;
      pq.push(arr[i].second);
      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }
      if (pq.size() == k)
        ret = std::max(ret, sum * minVal);
    }
    return ret;
  }
};
