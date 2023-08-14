#include <stack>
#include <vector>

class Solution {
public:
  long long subArrayRanges(std::vector<int> &nums) {
    int n = nums.size();

    std::stack<int> Stack;
    std::vector<int> nextSmaller(n, n);
    for (int i = 0; i < n; i++) {
      while (!Stack.empty() && nums[Stack.top()] > nums[i]) {
        nextSmaller[Stack.top()] = i;
        Stack.pop();
      }
      Stack.push(i);
    }

    while (!Stack.empty()) Stack.pop();
    std::vector<int> prevSmaller(n, -1);
    for (int i = n - 1; i >= 0; i--) {
      while (!Stack.empty() && nums[Stack.top()] >= nums[i]) {
        prevSmaller[Stack.top()] = i;
        Stack.pop();
      }
      Stack.push(i);
    }

    while (!Stack.empty()) Stack.pop();
    std::vector<int> nextGreater(n, n);
    for (int i = 0; i < n; i++) {
      while (!Stack.empty() && nums[Stack.top()] < nums[i]) {
        nextGreater[Stack.top()] = i;
        Stack.pop();
      }
      Stack.push(i);
    }

    while (!Stack.empty()) Stack.pop();
    std::vector<int> prevGreater(n, -1);
    for (int i = n - 1; i >= 0; i--) {
      while (!Stack.empty() && nums[Stack.top()] <= nums[i]) {
        prevGreater[Stack.top()] = i;
        Stack.pop();
      }
      Stack.push(i);
    }

    long long ret = 0;
    for (int i = 0; i < n; i++) {
      int l = prevGreater[i];
      int r = nextGreater[i];
      ret += (long long) nums[i] * (i - l) * (r - i);
    }
    for (int i = 0; i < n; i++) {
      int l = prevSmaller[i];
      int r = nextSmaller[i];
      ret -= (long long) nums[i] * (i - l) * (r - i);
    }
    return ret;
  }
};
