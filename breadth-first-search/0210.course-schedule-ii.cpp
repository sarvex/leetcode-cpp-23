#include <vector>

class Solution
{
public:
  std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites)
  {
    int n = numCourses;
    std::vector<std::vector<int>> nextCourses(n);
    std::vector<int> degree(n, 0);

    for (auto edge : prerequisites)
    {
      int a = edge[0];
      int b = edge[1];
      nextCourses[b].push_back(a);
      degree[a] += 1;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
      if (degree[i] == 0)
        q.push(i);

    std::vector<int> rets;
    while (!q.empty())
    {
      int cur = q.front();
      q.pop();
      rets.push_back(cur);

      for (auto next : nextCourses[cur])
      {
        degree[next] -= 1;
        if (degree[next] == 0)
          q.push(next);
      }
    }

    if (rets.size() != n)
      return {};
    else
      return rets;
  }
};
