#include <string>
#include <unordered_set>

class Solution
{
public:
  int kSimilarity(std::string A, std::string B)
  {
    if (A == B)
      return 0;

    std::queue<std::string> q;
    q.push(A);

    int step = -1;
    unordered_set<std::string> visited;
    visited.insert(A);

    while (!q.empty())
    {
      int len = q.size();
      step++;

      while (len--)
      {
        std::string str = q.front();
        q.pop();

        int i = 0;
        while (str[i] == B[i])
          i++;

        for (int j = i + 1; j < str.size(); j++)
        {
          if (str[j] != B[i])
            continue;

          std::string newStr = str;
          swap(newStr[i], newStr[j]);

          if (newStr == B)
            return step + 1;

          if (visited.find(newStr) == visited.end())
          {
            q.push(newStr);
            visited.insert(newStr);
          }

          // cout<<str<<": "<<newStr<<endl;
        }
      }
    }

    return -1;
  }
};
