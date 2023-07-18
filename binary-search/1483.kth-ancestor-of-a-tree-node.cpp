#include <vector>

class TreeAncestor
{
  std::vector<std::vector<int>> p;

public:
  TreeAncestor(int n, std::vector<int> &parent)
  {
    std::vector<std::vector<int>> p(n, std::vector<int>(20, -1)); // p[i][j] means the 2^j-th ancestor for node i
    for (int i = 0; i < n; i++)
      p[i][0] = parent[i];

    for (int j = 1; j < 20; j++)
      for (int i = 0; i < n; i++)
      {
        if (p[i][j - 1] != -1)
          p[i][j] = p[p[i][j - 1]][j - 1];
      }
    this->p = p;
  }

  int getKthAncestor(int node, int k)
  {
    for (int i = 0; i < 20; i++)
    {
      if ((k >> i) & 1)
      {
        node = p[node][i];
        if (node == -1)
          break;
      }
    }
    return node;
  }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
