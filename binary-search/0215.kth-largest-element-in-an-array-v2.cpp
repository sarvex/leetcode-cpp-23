#include <algorithm>
#include <vector>
class Solution
{
public:
  int findKthLargest(std::vector<int> &nums, int k)
  {
    return quickSelect(nums, 0, nums.size() - 1, k);
  }

  int quickSelect(std::vector<int> &nums, int a, int b, int k)
  {
    int pivot = nums[(a + b) / 2];

    int i = a, j = b;
    int t = a;
    while (t <= j)
    {
      if (nums[t] < pivot)
      {
        std::swap(nums[i], nums[t]);
        i++;
        t++;
      }
      else if (nums[t] > pivot)
      {
        std::swap(nums[j], nums[t]);
        j--;
      }
      else
        t++;
    }

    if (b - j >= k)
      return quickSelect(nums, j + 1, b, k);
    else if (b - i + 1 >= k)
      return pivot;
    else
      return quickSelect(nums, a, i - 1, k - (b - i + 1));
  }
};
