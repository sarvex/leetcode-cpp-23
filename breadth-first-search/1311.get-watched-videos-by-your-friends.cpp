#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
public:
  std::vector<string> watchedVideosByFriends(std::vector<std::vector<string>> &watchedVideos, std::vector<std::vector<int>> &friends, int id, int level)
  {
    int n = watchedVideos.size();
    std::vector<int> visited(n, 0);

    std::queue<int> q;
    q.push(id);
    visited[id] = 1;

    int step = 0;
    std::vector<int> persons;
    while (!q.empty())
    {
      int len = q.size();
      step += 1;
      while (len--)
      {
        int cur = q.front();
        q.pop();

        for (auto f : friends[cur])
        {
          if (visited[f] == 1)
            continue;
          visited[f] = 1;
          q.push(f);
          if (step == level)
            persons.push_back(f);
        }
      }
      if (step == level)
        break;
    }

    std::unordered_set<string> VideoSet;
    for (auto p : persons)
      for (auto v : watchedVideos[p])
        VideoSet.insert(v);

    std::unordered_map<string, int> freq;
    for (auto p : persons)
      for (auto v : watchedVideos[p])
        freq[v] += 1;

    std::vector<pair<int, string>> temp;
    for (auto v : VideoSet)
      temp.push_back({freq[v], v});
    sort(temp.begin(), temp.end());

    std::vector<string> rets;
    for (auto x : temp)
      rets.push_back(x.second);
    return rets;
  }
};
