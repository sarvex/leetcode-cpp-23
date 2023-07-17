/**
 * @link https://leetcode.com/problems/maximum-number-of-removable-characters/
 */
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
  std::unordered_map<int, int> pos; // idx of s -> idx of removable
public:
  int maximumRemovals(std::string s, std::string p, std::vector<int> &removable)
  {
    for (int i = 0; i < removable.size(); i++)
      pos[removable[i]] = i;

    int left = 0, right = removable.size();
    while (left < right)
    {
      int mid = right - (right - left) / 2;
      if (checkOK(s, p, mid))
        left = mid;
      else
        right = mid - 1;
    }
    return left;
  }

  bool checkOK(std::string &s, std::string &p, int k)
  {
    int i = 0, j = 0;
    int t = 0;
    while (j < p.size())
    {
      while (i < s.size() && s[i] != p[j])
        i++;

      if (i >= s.size())
        break;

      if (pos.find(i) == pos.end() || pos[i] >= k)
        j++;

      i++;
    }
    return j == p.size();
  }
};
