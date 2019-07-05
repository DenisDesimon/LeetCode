//#100 Same Tree - https://leetcode.com/problems/same-tree/
#include <iostream>
#include <cassert>
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        else if(p == NULL || q == NULL)
            return false;

        if(p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};

using namespace std;

int main()
{
    Solution solution;
    TreeNode* given_p = new TreeNode(1);
    given_p->left = new TreeNode(2);
    given_p->right = new TreeNode(3);

    TreeNode* given_q = new TreeNode(1);
    given_q->left = new TreeNode(2);
    given_q->right = new TreeNode(3);

    assert(solution.isSameTree(given_p, given_q) == true);

    return 0;
}
