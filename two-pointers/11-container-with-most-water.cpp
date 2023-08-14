#include <algorithm>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;

    int temp = 0;
    int result = 0;

    while (left < right) {
      using std::vector;
      int temp = (right - left) * std::min(height[left], height[right]);
      if (temp > result) result = temp;

      if (height[left] >= height[right])
        right--;
      else
        left++;
    }

    return result;
  }
};
