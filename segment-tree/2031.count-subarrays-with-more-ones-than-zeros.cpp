#include <vector>

class BIT {
public:
  int N;
  std::vector<long long> bitArr;// Note: all arrays are 1-index
  std::vector<long long> nums;
  long long M = 1e9 + 7;

  void init(int N) {
    this->N = N;
    bitArr.resize(N + 1);
    nums.resize(N + 1);
  }

  // increase nums[i] by delta
  void updateDelta(int i, long long delta) {
    int idx = i;
    while (idx <= N) {
      bitArr[idx] += delta;
      bitArr[idx] %= M;
      idx += idx & (-idx);
    }
  }

  // sum of a range nums[1:j] inclusively
  long long queryPreSum(int idx) {
    long long result = 0;
    while (idx) {
      result += bitArr[idx];
      result %= M;
      idx -= idx & (-idx);
    }
    return result;
  }

  // sum of a range nums[i:j] inclusively
  long long sumRange(int i, int j) {
    return queryPreSum(j) - queryPreSum(i - 1);
  }
};

class Solution {
  const static long long OFFSET = 1e5 + 10;
  const static long long M = 1e9 + 7;

public:
  int subarraysWithMoreZerosThanOnes(std::vector<int> &nums) {
    BIT bit;
    bit.init(2 * OFFSET);
    int diff = 0;
    long long ret = 0;
    bit.updateDelta(0 + OFFSET, 1);

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == 1) diff++;
      else
        diff--;

      ret = (ret + bit.queryPreSum(diff - 1 + OFFSET)) % M;
      bit.updateDelta(diff + OFFSET, 1);
    }
    return ret;
  }
};
