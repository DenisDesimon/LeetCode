//#814 Binary Tree Pruning - https://leetcode.com/problems/binary-tree-pruning/
#include <iostream>
#include <cassert>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      bool operator==(TreeNode b)
      {
          bool Left = false, mid, Right = false;
          mid = val == b.val;
          if(left == NULL && b.left == NULL)
              Left = true;
          else if(left != NULL && b.left != NULL){
              Left = *left == *b.left;
          }
          if(right == NULL && b.right == NULL)
              Right = true;
          else if(right != NULL && b.right != NULL)
              Right = *right == *b.right;
          return Left + Right + mid > 2;

      }
  };

class Solution {
    bool has_one(TreeNode* root)
    {
        if(root == NULL)
            return false;
        bool left = has_one(root->left);
        bool right = has_one(root->right);
        if(!left)
            root->left = NULL;
        if(!right)
            root->right = NULL;
        return root->val || left || right;

    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        return has_one(root) ? root : NULL;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->right = new TreeNode(0);
    given_tree->right->left = new TreeNode(0);
    given_tree->right->right = new TreeNode(1);

    TreeNode* expected_answer = new TreeNode(1);
    expected_answer->right = new TreeNode(0);
    expected_answer->right->right = new TreeNode(1);

    assert(*solution.pruneTree(given_tree) == *expected_answer);
    return 0;
}
