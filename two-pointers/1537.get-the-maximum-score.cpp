#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSum(std::vector<int> &nums1, std::vector<int> &nums2) {
    long m = nums1.size();
    long n = nums2.size();
    long long x = 0, y = 0;
    long long i = 0, j = 0;
    long long M = 1e9 + 7;

    while (i < m || j < n) {
      if (i == m) {
        y += nums2[j];
        j++;
      } else if (j == n) {
        x += nums1[i];
        i++;
      } else if (nums1[i] < nums2[j]) {
        x += nums1[i];
        i++;
      } else if (nums1[i] > nums2[j]) {
        y += nums2[j];
        j++;
      } else if (nums1[i] == nums2[j]) {
        x = std::max(x, y) + nums1[i];
        y = x;
        i++;
        j++;
      }
    }
    return std::max(x, y) % M;
  }
};
