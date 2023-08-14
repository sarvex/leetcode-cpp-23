#include <numeric>
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
    sort(arr.begin(), arr.end());

    long long totalCost = std::accumulate(cost.begin(), cost.end(), 0LL);
    long long curCost = 0;
    int k;
    for (int i = 0; i < arr.size(); i++) {
      curCost += arr[i].second;
      if (curCost >= totalCost * 1.0 / 2) {
        k = i;
        break;
      }
    }

    long long ret = 0;
    for (int i = 0; i < arr.size(); i++) {
      ret += abs(arr[i].first - arr[k].first) * arr[i].second;
    }
    return ret;
  }
};
