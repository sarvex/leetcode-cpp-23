#include <algorithm>
#include <vector>

class Solution {
  std::vector<std::vector<int>> rets;
  std::vector<int> visited;

public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    int n = nums.size();
    visited.resize(n);

    rets.push_back({});
    std::sort(nums.begin(), nums.end());
    std::vector<int> temp;
    dfs(nums, 0, temp);
    return rets;
  }

  void dfs(std::vector<int> &nums, int cur, std::vector<int> &temp) {
    if (cur == nums.size())
      return;

    for (int i = cur; i < nums.size(); i++) {
      if ((i >= 1 && nums[i] == nums[i - 1]) && visited[i - 1] == 0)
        continue;

      visited[i] = 1;
      temp.push_back(nums[i]);
      rets.push_back(temp);
      dfs(nums, i + 1, temp);
      temp.pop_back();
      visited[i] = 0;
    }
  }
};
