#include <algorithm>
#include <limits>
#include <vector>

class SegTreeNode {
public:
  SegTreeNode *left = NULL;
  SegTreeNode *right = NULL;
  int start, end;
  int info;// the maximum value of the range
  bool tag;

  SegTreeNode(int a, int b, int val)// init for range [a,b] with val
  {
    tag = 0;
    start = a, end = b;
    if (a == b) {
      info = val;
      return;
    }
    int mid = (a + b) / 2;
    if (left == NULL) {
      left = new SegTreeNode(a, mid, val);
      right = new SegTreeNode(mid + 1, b, val);
      info = std::max(left->info, right->info);// check with your own logic
    }
  }

  void pushDown() {
    if (tag == 1 && left) {
      left->info = info;
      right->info = info;
      left->tag = 1;
      right->tag = 1;
      tag = 0;
    }
  }

  void updateRange(int a, int b, int val)// set range [a,b] with val
  {
    if (b < start || a > end)// not covered by [a,b] at all
      return;
    if (a <= start && end <= b)// completely covered within [a,b]
    {
      info = val;
      tag = 1;
      return;
    }

    if (left) {
      pushDown();
      left->updateRange(a, b, val);
      right->updateRange(a, b, val);
      info = std::max(left->info, right->info);// write your own logic
    }
  }

  int queryRange(int a, int b)// query the maximum value within range [a,b]
  {
    if (b < start || a > end) {
      return INT_MIN;// check with your own logic
    }
    if (a <= start && end <= b) {
      return info;// check with your own logic
    }

    if (left) {
      pushDown();
      int ret = std::max(left->queryRange(a, b), right->queryRange(a, b));
      info = std::max(left->info, right->info);// check with your own logic
      return ret;
    }

    return info;// should not reach here
  }
};

class Solution {
  SegTreeNode *root;

public:
  int maximumRobots(std::vector<int> &chargeTimes, std::vector<int> &runningCosts, long long budget) {
    std::vector<std::pair<long long, long long>> robots;
    int n = chargeTimes.size();

    root = new SegTreeNode(0, n - 1, 0);
    for (int i = 0; i < n; i++)
      root->updateRange(i, i, chargeTimes[i]);

    long long left = 0, right = n;
    while (left < right) {
      long long mid = right - (right - left) / 2;
      if (isOK(mid, chargeTimes, runningCosts, budget))
        left = mid;
      else
        right = mid - 1;
    }
    return left;
  }

  bool isOK(long long k, std::vector<int> &chargeTimes, std::vector<int> &runningCosts, long long budget) {
    long long n = chargeTimes.size();
    long long sum = 0;

    for (int i = 0; i < n; i++) {
      sum += runningCosts[i];

      if (i >= k - 1) {
        long long ret = root->queryRange(i - k + 1, i) + (long long) k * sum;
        if (ret <= budget) return true;
        sum -= runningCosts[i - k + 1];
      }
    }

    return false;
  }
};
