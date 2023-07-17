/**
 * @link https://leetcode.com/problems/maximum-tastiness-of-candy-basket/
 */
#include <algorithm>
#include <limits>
#include <vector>

class Solution
{
public:
  int maximumTastiness(std::vector<int> &price, int k)
  {
    std::sort(price.begin(), price.end());

    int left = 0, right = std::numeric_limits<int>::max() / 2;
    while (left < right)
    {
      int mid = right - (right - left) / 2;
      if (isOK(price, mid, k))
        left = mid;
      else
        right = mid - 1;
    }
    return left;
  }

  bool isOK(std::vector<int> &price, int diff, int k)
  {
    int count = 1;
    for (int i = 0; i < price.size(); i++)
    {
      int j = i;
      while (j < price.size() && price[j] - price[i] < diff)
        j++;
      if (j < price.size())
      {
        count++;
        i = j - 1;
      }
      else
        break;

      if (count >= k)
        return true;
    }

    return false;
  }
};
