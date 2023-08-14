#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> countSmaller(std::vector<int> &nums) {
    int N = nums.size();
    if (N == 0) return {};

    std::vector<int> sortedNums = nums;
    std::vector<int> counts(N, 0);
    DivideConquer(nums, sortedNums, counts, 0, nums.size() - 1);// 0表示起点，N-1表示终点
    return counts;
  }

  void DivideConquer(std::vector<int> &nums, std::vector<int> &sortedNums, std::vector<int> &counts, int start, int end) {
    if (start == end) return;

    // 如果需要处理的元素有多个，则折半分治处理。注意：分治处理后的sortedNums前后两部分元素都是有序的。
    int mid = start + (end - start) / 2;
    DivideConquer(nums, sortedNums, counts, start, mid);
    DivideConquer(nums, sortedNums, counts, mid + 1, end);

    // OK，既然现在start~mid和mid+1~end这两段都分别有序，
    // 那么对于start~mid中的任何一个元素，我们都可以轻易地知道在mid+1~end中有多少小于它的数
    for (int i = start; i <= mid; i++) {
      int val = nums[i];
      auto pos = lower_bound(sortedNums.begin() + mid + 1, sortedNums.begin() + end + 1, val);
      counts[i] += pos - (sortedNums.begin() + mid + 1);
    }

    // 将两段已经有序的数组段start~mid,mid+1~end合起来排序。
    std::inplace_merge(sortedNums.begin() + start, sortedNums.begin() + mid + 1, sortedNums.begin() + end + 1);
  }
};
