#include <algorithm>
#include <vector>

class Solution {
public:
  int minSubArrayLen(int s, std::vector<int> &nums) {
    int i = 0;
    int j = 0;
    int sum = 0;
    int len = std::numeric_limits<int>::max();

    for (int j = 0; j < nums.size(); j++) {
      sum += nums[j];

      if (sum < s)
        continue;
      else {
        while (sum >= s) {
          len = std::min(len, j - i + 1);
          sum -= nums[i];
          i++;
        }
      }
    }

    if (len == std::numeric_limits<int>::max())
      len = 0;

    return len;
  }
};
