//#99 Recover Binary Search Tree - https://leetcode.com/problems/recover-binary-search-tree/
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
    TreeNode *first = NULL, *second = NULL, *prev = NULL;
    void inorder(TreeNode* root){
        if(root == NULL)
            return;
        inorder(root->left);
        if(prev && prev->val > root->val)
        {
            if(!first)
                first = prev;
            second = root;
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;

    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(3);
    given_tree->left->right = new TreeNode(2);

    TreeNode* expected_answer = new TreeNode(3);
    expected_answer->left = new TreeNode(1);
    expected_answer->left->right = new TreeNode(2);

    solution.recoverTree(given_tree);
    assert(*given_tree == *expected_answer);

    return 0;
}
