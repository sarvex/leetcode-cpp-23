#include <algorithm>
#include <vector>

class Solution {
public:
  int rob(std::vector<int> &nums) {
    if (nums.size() == 0) return 0;

    int rob = nums[0], norob = 0;

    for (int i = 1; i < nums.size(); i++) {
      int rob_tmp = rob, norob_tmp = norob;
      norob = std::max(rob_tmp, norob_tmp);
      rob = norob_tmp + nums[i];
    }
    return std::max(rob, norob);
  }
};
