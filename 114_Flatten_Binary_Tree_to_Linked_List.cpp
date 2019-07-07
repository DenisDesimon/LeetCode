//#114 Flatten Binary Tree to Linked List - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    TreeNode* prev = NULL;
    void build(TreeNode* root){
        if(root == NULL)
            return;
        build(root->right);
        build(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
public:
    void flatten(TreeNode* root) {
        build(root);
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(5);
    given_tree->left->left = new TreeNode(3);
    given_tree->left->right = new TreeNode(4);
    given_tree->right->right = new TreeNode(6);

    TreeNode* expected_answer = new TreeNode(1);
    expected_answer->right = new TreeNode(2);
    expected_answer->right->right = new TreeNode(3);
    expected_answer->right->right->right = new TreeNode(4);
    expected_answer->right->right->right->right = new TreeNode(5);
    expected_answer->right->right->right->right->right = new TreeNode(6);

    solution.flatten(given_tree);
    assert(*given_tree == *expected_answer);

    return 0;
}

