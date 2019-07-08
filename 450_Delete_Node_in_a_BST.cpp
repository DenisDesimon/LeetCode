//#450 Delete Node in a BST - https://leetcode.com/problems/delete-node-in-a-bst/
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
      TreeNode* deleteNode(TreeNode* root, int key) {
          TreeNode** node = &root;
          while(true)
          {
              if(*node == NULL)
                  return root;
              if((*node)->val > key)
                  node = &(*node)->left;
              else if((*node)->val < key)
                  node = &(*node)->right;
              else
                  break;
          }
          if((*node)->left != NULL)
          {
              auto temp = (*node)->right;
              (*node) = (*node)->left;
              while((*node)->right != NULL)
                  node = &(*node)->right;
              (*node)->right = temp;
          }
          else if((*node)->right != NULL)
          {
              (*node) = (*node)->right;
          }
          else
              (*node) = NULL;
          return root;

      }
  };


  int main()
  {
      Solution solution;
      TreeNode *given_tree = new TreeNode(5);
      given_tree->left = new TreeNode(3);
      given_tree->right = new TreeNode(6);
      given_tree->left->left = new TreeNode(2);
      given_tree->left->right = new TreeNode(4);
      given_tree->right->right = new TreeNode(7);

      TreeNode* expected_answer = new TreeNode(5);
      expected_answer->left = new TreeNode(2);
      expected_answer->right = new TreeNode(6);
      expected_answer->left->right = new TreeNode(4);
      expected_answer->right->right = new TreeNode(7);

      assert(*solution.deleteNode(given_tree, 3) == *expected_answer);

      return 0;
  }
