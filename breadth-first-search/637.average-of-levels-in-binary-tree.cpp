#include <vector>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  std::vector<double> averageOfLevels(TreeNode *root)
  {
    queue<TreeNode *> q;
    q.push(root);

    std::vector<double> results;

    while (!q.empty())
    {
      int n = q.size();
      double sum = 0;
      for (int i = 0; i < n; i++)
      {
        TreeNode *node = q.front();
        sum += node->val;
        if (node->left != NULL)
          q.push(node->left);
        if (node->right != NULL)
          q.push(node->right);
        q.pop();
      }
      results.push_back(sum / n);
    }

    return results;
  }
};
