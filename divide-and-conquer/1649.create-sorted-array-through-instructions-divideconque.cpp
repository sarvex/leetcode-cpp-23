#include <algorithm>
#include <vector>

class Solution {
  int numSmaller[100005];
  int temp[100005];
  int count[100005];
  int sorted[100005];
  int M = 1e9 + 7;

public:
  int createSortedArray(std::vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++)
      sorted[i] = nums[i];

    helper(nums, 0, n - 1);
    int ret = 0;
    for (int i = 0; i < n; i++) {
      ret += std::min(numSmaller[i], i - count[nums[i]] - numSmaller[i]);
      ret %= M;
      count[nums[i]]++;
    }
    return ret;
  }

  void helper(std::vector<int> &nums, int a, int b) {
    if (a >= b) return;
    int mid = a + (b - a) / 2;
    helper(nums, a, mid);
    helper(nums, mid + 1, b);

    for (int i = mid + 1; i <= b; i++) {
      auto iter = std::lower_bound(sorted + a, sorted + mid + 1, nums[i]);
      numSmaller[i] += iter - (sorted + a);
    }

    std::inplace_merge(sorted + a, sorted + mid + 1, sorted + b + 1);

    // int i=a, j=mid+1, p = 0;
    // while (i<=mid && j<=b)
    // {
    //     if (sorted[i]<=sorted[j])
    //     {
    //         temp[p] = sorted[i];
    //         i++;
    //     }
    //     else
    //     {
    //         temp[p] = sorted[j];
    //         j++;
    //     }
    //     p++;
    // }
    // while (i<=mid)
    // {
    //     temp[p] = sorted[i];
    //     i++;
    //     p++;
    // }
    // while (j<=b)
    // {
    //     temp[p] = sorted[j];
    //     j++;
    //     p++;
    // }
    // for (int i=0; i<b-a+1; i++)
    //     sorted[a+i] = temp[i];
  }
};
