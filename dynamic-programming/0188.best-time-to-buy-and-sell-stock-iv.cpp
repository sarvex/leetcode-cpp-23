#include <algorithm>
#include <limits>
#include <vector>

class Solution {
public:
  int maxProfit(int k, std::vector<int> &prices) {
    int n = prices.size();

    if (k >= n / 2) {
      int result = 0;
      for (int i = 1; i < prices.size(); i++)
        if (prices[i] > prices[i - 1])
          result += prices[i] - prices[i - 1];
      return result;
    }

    std::vector<int> hold(k + 1, std::numeric_limits<int>::min() / 2);
    std::vector<int> sold(k + 1, std::numeric_limits<int>::min() / 2);

    hold[0] = 0;
    sold[0] = 0;

    for (int i = 0; i < n; i++) {
      auto hold_old = hold;
      auto sold_old = sold;

      for (int j = 1; j <= k; j++) {
        hold[j] = std::max(sold_old[j - 1] - prices[i], hold_old[j]);
        sold[j] = std::max(hold_old[j] + prices[i], sold_old[j]);
      }
    }

    int result = std::numeric_limits<int>::min();
    for (int j = 0; j <= k; j++)
      result = std::max(result, sold[j]);
    return result;
  }
};
