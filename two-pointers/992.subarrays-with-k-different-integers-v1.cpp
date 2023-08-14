#include <unordered_map>
#include <vector>

class Solution {
public:
  int subarraysWithKDistinct(std::vector<int> &A, int K) {
    return atMostK(A, K) - atMostK(A, K - 1);
  }

  int atMostK(std::vector<int> &A, int K) {
    std::unordered_map<int, int> Map;
    int count = 0;
    int i = 0;

    for (int j = 0; j < A.size(); j++) {
      Map[A[j]]++;

      while (Map.size() > K) {
        Map[A[i]]--;
        if (Map[A[i]] == 0)
          Map.erase(A[i]);
        i++;
      }
      count += j - i + 1;
    }
    return count;
  }
};
