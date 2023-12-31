#include <vector>

class Solution
{
public:
  std::vector<int> xorQueries(std::vector<int> &arr, std::vector<std::vector<int>> &queries)
  {
    std::vector<int> q({0});
    for (int i = 0; i < arr.size(); i++)
      q.push_back(q.back() ^ arr[i]);

    std::vector<int> rets;
    for (auto query : queries)
    {
      int a = query[0] + 1;
      int b = query[1] + 1;
      rets.push_back(q[a - 1] ^ q[b]);
    }
    return rets;
  }
};
