#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
  long long minCost(std::vector<int> &nums, std::vector<int> &cost) {
    int n = nums.size();
    std::vector<std::pair<long long, long long>> arr;
    for (int i = 0; i < n; i++) {
      arr.push_back({nums[i], cost[i]});
    }
    std::sort(arr.begin(), arr.end());

    std::vector<long long> left(n, 0);
    long long sum = arr[0].second;
    for (int i = 1; i < n; i++) {
      long long delta = arr[i].first - arr[i - 1].first;
      left[i] = left[i - 1] + delta * sum;
      sum += arr[i].second;
    }

    std::vector<long long> right(n, 0);
    sum = arr[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
      long long delta = arr[i + 1].first - arr[i].first;
      right[i] = right[i + 1] + delta * sum;
      sum += arr[i].second;
    }

    std::vector<long long> all(n, 0);
    for (int i = 0; i < n; i++)
      all[i] = (left[i] + right[i]);

    return *min_element(all.begin(), all.end());
  }
};
