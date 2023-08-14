#include <algorithm>
#include <vector>

class Solution {
public:
  long long minSumSquareDiff(std::vector<int> &nums1, std::vector<int> &nums2, int k1, int k2) {
    std::vector<long long> nums;
    for (int i = 0; i < nums1.size(); i++)
      nums.push_back(abs(nums1[i] - nums2[i]));
    std::sort(nums.rbegin(), nums.rend());

    int n = nums.size();
    std::vector<long long> presum(n);
    presum[0] = nums[0];
    for (int i = 1; i < n; i++)
      presum[i] = presum[i - 1] + nums[i];
    long long ret = 0;

    int k = k1 + k2;
    if (presum[n - 1] <= k)
      return 0;

    int i = 0;
    while (i < n && (presum[i] - nums[i] * (i + 1) <= k))
      i++;
    i--;

    long long diff = k - (presum[i] - nums[i] * (i + 1));
    long long each = diff / (i + 1);
    long long extra = diff % (i + 1);

    int a = extra;    // nums[i]-each-1;
    int b = i + 1 - a;// nums[i]-each;

    ret += (nums[i] - each - 1) * (nums[i] - each - 1) * a;
    ret += (nums[i] - each) * (nums[i] - each) * b;

    for (int j = i + 1; j < n; j++)
      ret += nums[j] * nums[j];

    return ret;
  }
};
