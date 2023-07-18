#include <vector>

class Solution
{
  unordered_set<int> key;
  int ret = 0;

public:
  int maxCandies(std::vector<int> &status, std::vector<int> &candies, std::vector<std::vector<int>> &keys, std::vector<std::vector<int>> &containedBoxes, std::vector<int> &initialBoxes)
  {
    queue<int> q;
    for (auto b : initialBoxes)
      q.push(b);

    bool changed = 1;
    while (q.size() > 0 && changed)
    {
      changed = 0;
      int len = q.size();
      while (len--)
      {
        int b = q.front();
        q.pop();

        if (status[b] == 0 && key.find(b) == key.end())
        {
          q.push(b);
        }
        else
        {
          changed = 1;
          ret += candies[b];
          for (auto k : keys[b])
            key.insert(k);
          for (auto bb : containedBoxes[b])
            q.push(bb);
        }
      }
    }
    return ret;
  }
};
