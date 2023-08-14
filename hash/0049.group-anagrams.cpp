#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
  {
    std::unordered_map<std::string, std::vector<std::string>> Map;

    for (int i = 0; i < strs.size(); i++)
    {
      std::string t = strs[i];
      std::sort(t.begin(), t.end());
      Map[t].push_back(strs[i]);
    }

    std::vector<std::vector<std::string>> results;
    for (auto a : Map)
      results.push_back(a.second);

    return results;
  }
};
