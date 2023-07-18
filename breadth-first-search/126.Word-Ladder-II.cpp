/**
 * @link https://leetcode.com/problems/word-ladder-ii
 */

#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
public:
  std::unordered_set<std::string> wordSet;
  std::unordered_map<std::string, std::vector<std::string>> next;
  std::unordered_map<std::string, std::unordered_set<std::string>> prev;
  std::vector<std::vector<std::string>> results;
  std::string beginWord;

  std::vector<std::vector<std::string>> findLadders(std::string beginWord, std::string endWord, std::vector<std::string> &wordList)
  {
    wordList.push_back(beginWord);

    for (auto str : wordList)
      wordSet.insert(str);
    this->beginWord = beginWord;

    if (wordSet.find(endWord) == wordSet.end())
      return {};

    for (int i = 0; i < wordList.size(); i++)
    {
      std::string str = wordList[i];
      for (int k = 0; k < str.size(); k++)
      {
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
          std::string temp = str;
          temp[k] = ch;
          if (temp == str)
            continue;
          if (wordSet.find(temp) != wordSet.end())
            next[str].push_back(temp);
        }
      }
    }

    std::unordered_set<std::string> visited;
    std::queue<std::string> q;
    int flag = 0;

    q.push(beginWord);
    visited.insert(beginWord);

    while (!q.empty())
    {
      int len = q.size();
      std::unordered_set<string> newVisited;

      for (int k = 0; k < len; k++)
      {
        string str = q.front();
        q.pop();

        for (auto nextStr : next[str])
        {
          if (visited.find(nextStr) != visited.end())
            continue;
          prev[nextStr].insert(str);
          newVisited.insert(nextStr);

          if (nextStr == endWord)
            flag = 1;
        }
      }

      for (auto x : newVisited)
      {
        visited.insert(x);
        q.push(x);
      }

      if (flag == 1)
        break;
    }

    if (flag == 0)
      return {};

    DFS(endWord, {endWord});

    return results;
  }

  void DFS(string word, std::vector<string> path)
  {
    if (word == beginWord)
    {
      reverse(path.begin(), path.end());
      results.push_back(path);
      return;
    }

    for (auto preStr : prev[word])
    {
      std::vector<string> newPath = path;
      newPath.push_back(preStr);
      DFS(preStr, newPath);
    }
    return;
  }
};
