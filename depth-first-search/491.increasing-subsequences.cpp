#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> findSubsequences(std::vector<int> &nums) {
    std::vector<std::vector<int>> results;
    std::vector<int> curRes;
    DFS(nums, 0, curRes, results);
    return results;
  }

  void DFS(std::vector<int> &nums, int idx, std::vector<int> &curRes, std::vector<std::vector<int>> &results) {
    if (curRes.size() > 1) results.push_back(curRes);
    if (idx == nums.size()) return;

    std::unordered_set<int> Set;
    for (int i = idx; i < nums.size(); i++) {
      if (curRes.size() != 0 && nums[i] < curRes.back()) continue;
      if (Set.find(nums[i]) != Set.end()) continue;
      Set.insert(nums[i]);

      curRes.push_back(nums[i]);
      DFS(nums, i + 1, curRes, results);
      curRes.pop_back();
    }
  }
};
