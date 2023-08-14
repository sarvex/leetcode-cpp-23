#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
  int total;
  int k;
  int visited[16];

public:
  bool canPartitionKSubsets(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.end());
    total = std::accumulate(nums.begin(), nums.end(), 0);
    this->k = k;
    if (total % k != 0) return false;

    return dfs(nums, 0, 0, 0);
  }

  bool dfs(std::vector<int> &nums, int cur, int group, int sum) {
    if (group == k)
      return true;

    if (sum > total / k)
      return false;

    if (sum == total / k)
      return dfs(nums, 0, group + 1, 0);

    int last = -1;
    for (int i = cur; i < nums.size(); i++) {
      if (visited[i] == 1) continue;
      if (nums[i] == last) continue;
      last = nums[i];
      visited[i] = 1;
      if (dfs(nums, i, group, sum + nums[i]))
        return true;
      visited[i] = 0;
    }
    return false;
  }
};
