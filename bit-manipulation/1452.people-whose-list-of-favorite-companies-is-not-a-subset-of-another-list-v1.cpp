#include <string>
#include <unordered_set>
#include <vector>

class Solution
{
public:
  std::vector<int> peopleIndexes(std::vector<std::vector<std::string>> &favoriteCompanies)
  {
    std::vector<std::unordered_set<std::string>> arr;
    for (int i = 0; i < favoriteCompanies.size(); i++)
    {
      std::unordered_set<std::string> Set(favoriteCompanies[i].begin(), favoriteCompanies[i].end());
      arr.push_back(Set);
    }

    std::vector<int> rets;
    for (int i = 0; i < arr.size(); i++)
    {
      int flag = 1;
      for (int j = 0; j < arr.size(); j++)
      {
        if (i == j)
          continue;
        bool include = 1; // check if i-th set is included in j-th set
        for (auto c : arr[i])
        {
          if (arr[j].find(c) == arr[j].end())
          {
            include = 0;
            break;
          }
        }
        if (include == 1) // If included, disqualification
        {
          flag = 0;
          break;
        }
      }
      if (flag == 1)
        rets.push_back(i);
    }

    return rets;
  }
};
