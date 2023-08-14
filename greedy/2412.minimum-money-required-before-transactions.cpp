#include <algorithm>
#include <vector>

class Solution {
public:
  long long minimumMoney(vector<vector<int>> &transactions) {
    sort(transactions.begin(), transactions.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
    long long maxCostForNetGain = 0;

    long long cur = 0;
    long long histLow = 0;

    for (auto &trans: transactions) {
      long long cost = trans[0], back = trans[1];
      if (cost <= back) {
        maxCostForNetGain = std::max(maxCostForNetGain, cost);
      } else {
        cur -= cost;
        histLow = std::min(histLow, cur);
        cur += back;
      }
    }

    cur -= maxCostForNetGain;
    histLow = std::min(histLow, cur);

    return abs(histLow);
  }
};
