//#235 Lowest Common Ancestor of a Binary Search Tree - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include <iostream>
#include <queue>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(true)
        {
            if(p->val > root->val && q->val > root->val)
                root = root->right;
            else if(p->val < root->val && q->val < root->val)
                root = root->left;
            else
                break;
        }
        return root;

    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(4);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(7);
    given_tree->left->left = new TreeNode(1);
    given_tree->left->right = new TreeNode(3);
    given_tree->right->left = new TreeNode(6);
    given_tree->right->right = new TreeNode(9);

    assert(solution.lowestCommonAncestor(given_tree, given_tree->left->right, given_tree->right) == given_tree);

    return 0;
}
