#include <algorithm>
#include <vector>

class Solution {
public:
  long long makeSubKSumEqual(std::vector<int> &arr, int k) {
    int n = arr.size();
    long long ret = 0;
    std::vector<int> visited(n);

    for (int i = 0; i < k; i++) {
      std::vector<int> nums;
      int j = i;
      while (visited[j] == 0) {
        visited[j] = 1;
        nums.push_back(arr[j]);
        j = (j + k) % n;
      }
      ret += helper(nums);
    }
    return ret;
  }

  long long helper(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    long long ret = 0;
    for (int i = 0; i < n; i++)
      ret += (long long) abs(nums[i] - nums[n / 2]);
    return ret;
  }
};
