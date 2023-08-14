#include <stack>
#include <vector>

class Solution {
  const static long long M = 1e9 + 7;

public:
  int totalStrength(std::vector<int> &nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 0);

    std::vector<long long> presum(n + 2, 0);
    for (int i = 1; i <= n; i++)
      presum[i] = (presum[i - 1] + (long long) nums[i]) % M;

    std::vector<long long> presum2(n + 2, 0);
    for (int i = 1; i <= n; i++)
      presum2[i] = (presum2[i - 1] + (long long) nums[i] * i) % M;

    std::stack<int> Stack;
    std::vector<int> nextSmaller(n + 2, n + 1);
    std::vector<int> prevSmaller(n + 2, 0);
    for (int i = 1; i <= n; i++) {
      while (!Stack.empty() && nums[Stack.top()] > nums[i]) {
        nextSmaller[Stack.top()] = i;
        Stack.pop();
      }
      if (!Stack.empty())
        prevSmaller[i] = Stack.top();
      Stack.push(i);
    }

    long long ret = 0;
    for (int i = 1; i <= n; i++) {
      long long a = prevSmaller[i], b = nextSmaller[i];
      long long x = i - a, y = b - i;
      long long first = ((presum2[i - 1] - presum2[a]) - (presum[i - 1] - presum[a]) * a % M + M) % M;
      first = first * y % M;
      long long second = ((presum[b - 1] - presum[i]) * (b - 1 + 1) - (presum2[b - 1] - presum2[i]) + M) % M;
      second = second * x % M;
      long long mid = (long long) nums[i] * x * y % M;

      ret = (ret + (first + second + mid) * nums[i]) % M;
    }

    return ret;
  }
};
