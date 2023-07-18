#include <unordered_set>
#include <vector>

class Solution
{
public:
  int subarrayBitwiseORs(std::vector<int> &A)
  {
    std::unordered_set<int> Set;
    std::unordered_set<int> All;
    for (int x : A)
    {
      std::unordered_set<int> temp;
      for (int y : Set)
      {
        temp.insert(y | x);
        All.insert(y | x);
      }
      temp.insert(x);
      All.insert(x);
      Set = temp;
    }
    return All.size();
  }
};
