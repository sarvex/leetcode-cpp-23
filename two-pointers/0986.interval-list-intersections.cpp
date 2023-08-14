#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> intervalIntersection(std::vector<std::vector<int>> &firstList, std::vector<std::vector<int>> &secondList) {
    int m = firstList.size();
    int n = secondList.size();
    int i = 0, j = 0;
    std::vector<std::vector<int>> rets;
    while (i < m && j < n) {
      if (firstList[i][1] < secondList[j][0])
        i++;
      else if (firstList[i][0] > secondList[j][1])
        j++;
      else {
        int start = std::max(firstList[i][0], secondList[j][0]);
        int end = std::min(firstList[i][1], secondList[j][1]);
        rets.push_back({start, end});
        if (firstList[i][1] < secondList[j][1])
          i++;
        else
          j++;
      }
    }
    return rets;
  }
};
