//#226 Invert Binary Tree - https://leetcode.com/problems/invert-binary-tree/
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
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        root->left = right;
        root->right = left;
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

    TreeNode* expected_answer = new TreeNode(4);
    expected_answer->left = new TreeNode(7);
    expected_answer->right = new TreeNode(2);
    expected_answer->left->left = new TreeNode(9);
    expected_answer->left->right = new TreeNode(6);
    expected_answer->right->left = new TreeNode(3);
    expected_answer->right->right = new TreeNode(1);

    assert(*solution.invertTree(given_tree) == *expected_answer);

    return 0;
}
