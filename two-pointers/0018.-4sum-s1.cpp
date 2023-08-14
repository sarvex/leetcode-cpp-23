#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    std::vector<std::vector<int>> results;
    if (nums.size() < 4) return results;

    std::sort(nums.begin(), nums.end());

    for (size_t a = 0; a < nums.size(); a++) {
      if (nums[a] * 4 > target) break;
      if (nums[a] + nums.back() * 3 < target) continue;

      if (a > 0 && nums[a] == nums[a - 1]) continue;

      for (size_t b = a + 1; b < nums.size(); b++) {
        if (nums[a] + nums[b] * 3 > target) break;
        if (nums[a] + nums[b] + nums.back() * 2 < target) continue;

        if (b > a + 1 && nums[b] == nums[b - 1]) continue;

        int left = b + 1;
        int right = nums.size() - 1;
        if (nums[a] + nums[b] + nums[left] * 2 > target) break;

        while (left < right) {
          if (nums[a] + nums[b] + nums[left] + nums[right] == target) {
            std::vector<int> temp = {nums[a], nums[b], nums[left], nums[right]};
            results.push_back(temp);
            left++;
            right--;
            while (nums[left] == nums[left - 1]) left++;
            while (nums[right] == nums[right + 1]) right--;

          } else if (nums[a] + nums[b] + nums[left] + nums[right] > target)
            right--;
          else if (nums[a] + nums[b] + nums[left] + nums[right] < target)
            left++;
        }
      }
    }
    return results;
  }
};
