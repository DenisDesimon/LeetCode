//#701 Insert into a Binary Search Tree - https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
      TreeNode* insertIntoBST(TreeNode* root, int val) {
          auto node = root;
          while(node != NULL)
          {
              if(node->val > val)
              {
                  if(node->left == NULL)
                  {
                      node->left = new TreeNode(val);
                      break;
                  }
                  node = node->left;
              }
              else
              {
                  if(node->right == NULL)
                  {
                      node->right = new TreeNode(val);
                      break;
                  }
                  node = node->right;
              }
          }
          return root;
      }
  };

  int main()
  {
      Solution solution;
      TreeNode *given_tree = new TreeNode(40);
      given_tree->left = new TreeNode(20);
      given_tree->right = new TreeNode(60);
      given_tree->left->left = new TreeNode(10);
      given_tree->left->right = new TreeNode(30);
      given_tree->right->left = new TreeNode(50);
      given_tree->right->right = new TreeNode(70);

      TreeNode* expected_answer = new TreeNode(40);
      expected_answer->left = new TreeNode(20);
      expected_answer->right = new TreeNode(60);
      expected_answer->left->left = new TreeNode(10);
      expected_answer->left->right = new TreeNode(30);
      expected_answer->right->left = new TreeNode(50);
      expected_answer->right->right = new TreeNode(70);
      expected_answer->left->right->left = new TreeNode(25);

      int given_val = 25;
      assert(*solution.insertIntoBST(given_tree, given_val) == *expected_answer);

      return 0;
  }
