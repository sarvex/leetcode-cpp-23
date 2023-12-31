#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int lengthOfLongestSubstringKDistinct(std::string s, int k) {
    std::vector<int> freq(256, 0);
    int count = 0;
    int i = 0;
    size_t ret = 0;
    for (size_t j = 0; j < s.size(); j++) {
      freq[s[j]]++;
      if (freq[s[j]] == 1) count++;

      while (count > k) {
        freq[s[i]]--;
        if (freq[s[i]] == 0)
          count--;
        i++;
      }
      ret = std::max(ret, j - i + 1);
    }
    return ret;
  }
};
