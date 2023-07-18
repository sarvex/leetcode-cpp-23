#include <bitset>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution
{
public:
  std::vector<int> peopleIndexes(std::vector<std::vector<std::string>> &favoriteCompanies)
  {
    int n = favoriteCompanies.size();
    std::unordered_map<std::string, std::bitset<100>> c2p;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < favoriteCompanies[i].size(); j++)
        c2p[favoriteCompanies[i][j]][i] = 1;

    std::vector<int> ret;
    for (int i = 0; i < n; i++)
    {
      std::bitset<100> bs;
      bs.set();

      for (std::string c : favoriteCompanies[i])
      {
        bs &= c2p[c];
      }
      if (bs.count() == 1)
        ret.push_back(i);
    }
    return ret;
  }
};
