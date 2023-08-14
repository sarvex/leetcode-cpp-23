#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution
{
public:
  int ladderLength(std::string beginWord, std::string endWord, vector<std::string> &wordList)
  {
    std::unordered_map<std::string, vector<std::string>> Map;
    std::unordered_map<std::string, int> visited;
    std::unordered_set<std::string> Set;
    for (int i = 0; i < wordList.size(); i++)
    {
      Set.insert(wordList[i]);
      visited[wordList[i]] = 0;
    }

    wordList.push_back(beginWord);
    for (int i = 0; i < wordList.size(); i++)
    {
      std::string s = wordList[i];
      for (int j = 0; j < s.size(); j++)
      {
        std::string t = s;
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          if (ch == s[j])
            continue;
          t[j] = ch;
          if (Set.find(t) != Set.end())
            Map[s].push_back(t);
        }
      }
    }

    queue<std::string> q;
    q.push(beginWord);
    int step = 1;

    while (!q.empty())
    {
      int len = q.size();
      while (len--)
      {
        std::string s = q.front();
        q.pop();
        for (auto t : Map[s])
        {
          if (visited[t] == 1)
            continue;
          if (t == endWord)
            return step + 1;
          visited[t] = 1;
          q.push(t);
        }
      }
      step++;
    }
    return 0;
  }
};
