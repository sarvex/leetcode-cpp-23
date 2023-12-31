#include <limits>
#include <vector>

class Solution {
  int ret = std::numeric_limits<int>::max();

public:
  int minAbsDifference(std::vector<int> &nums, int goal) {
    int m = nums.size() / 2;
    int n = nums.size() - m;
    std::vector<int> nums1(nums.begin(), nums.begin() + m);
    std::vector<int> nums2(nums.begin() + m, nums.end());

    std::vector<int> a = getSubSetsSum(nums1);
    std::vector<int> b = getSubSetsSum(nums2);

    findAns(a, b, goal);
    findAns(b, a, goal);
    return ret;
  }

  // std::vector<int> getSubSetsSum(std::vector<int>&nums)
  // {
  //     std::vector<int> sums;
  //     int m = nums.size();
  //     for (int state=0; state<(1<<m); state++)
  //     {
  //         int sum = 0;
  //         for (int i=0; i<32; i++)
  //         {
  //             if ((state>>i)&1)
  //                 sum += nums[i];
  //         }
  //         sums.push_back(sum);
  //     }
  //     sort(sums.begin(), sums.end());
  //     return sums;
  // }

  std::vector<int> getSubSetsSum(std::vector<int> &nums) {
    std::vector<int> sums({0});
    for (int x: nums) {
      std::vector<int> temp;
      int i = 0, j = 0, n = sums.size();
      while (i < n && j < n) {
        if (sums[i] + x < sums[j]) {
          temp.push_back(sums[i] + x);
          i++;
        } else {
          temp.push_back(sums[j]);
          j++;
        }
      }
      while (i < n) {
        temp.push_back(sums[i] + x);
        i++;
      }
      while (j < n) {
        temp.push_back(sums[j]);
        j++;
      }
      sums = temp;
    }
    return sums;
  }

  void findAns(std::vector<int> &a, std::vector<int> &b, int goal) {
    for (auto x: a) {
      auto iter = lower_bound(b.begin(), b.end(), goal - x);
      if (iter != b.end())
        ret = min(ret, abs(goal - x - *iter));
      if (iter != b.begin())
        ret = min(ret, abs(goal - x - *prev(iter)));
    }
  }
};
