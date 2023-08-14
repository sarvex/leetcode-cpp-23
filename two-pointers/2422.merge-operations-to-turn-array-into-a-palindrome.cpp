#include <vector>

class Solution {
public:
  int minimumOperations(std::vector<int> &nums) {
    int i = 0, j = nums.size() - 1;
    long long left = nums[i], right = nums[j];
    int count = 0;

    while (i < j) {
      if (left == right) {
        i++;
        j--;
        left = nums[i];
        right = nums[j];
      } else if (left < right) {
        i++;
        left += nums[i];
        count++;
      } else if (left > right) {
        j--;
        right += nums[j];
        count++;
      }
    }
    return count;
  }
};
