#include <unordered_set>
#include <vector>

class Node
{
public:
  int val;
  std::vector<Node *> children;

  Node() {}

  Node(int _val)
  {
    val = _val;
  }

  Node(int _val, std::vector<Node *> _children)
  {
    val = _val;
    children = _children;
  }
};

class Solution
{
  std::unordered_set<Node *> Set;

public:
  Node *findRoot(std::vector<Node *> tree)
  {
    int n = tree.size();
    for (auto node : tree)
    {
      if (Set.find(node) != Set.end())
        continue;
      for (auto child : node->children)
        dfs(child);
    }
    for (auto node : tree)
    {
      if (Set.find(node) == Set.end())
        return node;
    }
    return NULL;
  }

  void dfs(Node *node)
  {
    if (Set.find(node) != Set.end())
      return;
    Set.insert(node);
    for (auto child : node->children)
      dfs(child);
  }
};
