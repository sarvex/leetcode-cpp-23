#include <algorithm>
#include <vector>

class Solution {
public:
  int threeSumClosest(std::vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    int temp = std::numeric_limits<int>::max();
    int result;

    for (int a = 0; a < nums.size(); a++) {
      int left = a + 1;
      int right = nums.size() - 1;
      int sum = target - nums[a];

      while (left < right) {
        if (temp > std::abs(nums[left] + nums[right] - sum)) {
          temp = std::abs(nums[left] + nums[right] - sum);
          result = nums[a] + nums[left] + nums[right];
        }
        if (nums[left] + nums[right] == sum)
          return target;
        else if (nums[left] + nums[right] > sum)
          right--;
        else if (nums[left] + nums[right] < sum)
          left++;
      }
    }

    return result;
  }
};
