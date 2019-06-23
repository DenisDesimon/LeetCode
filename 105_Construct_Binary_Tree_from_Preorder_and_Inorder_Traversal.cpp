//#105 Construct Binary Tree from Preorder and Inorder Traversal - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


  //Definition for a binary tree node.
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
      TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end, int pre) {
          if(start > end)
              return NULL;
          else if(start == end)
              return new TreeNode(inorder[start]);
          TreeNode* root = new TreeNode(preorder[pre]);
          int index = -1;
          for(int i = start; i <= end; i++)
          {
              if(inorder[i] == preorder[pre])
              {
                  index = i;
                  break;
              }
          }
          root->left = buildTree(preorder, inorder, start, index - 1, pre + 1);
          root->right = buildTree(preorder, inorder, index + 1, end, index + pre - start + 1);
          return root;

      }
  public:
      TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
          return buildTree(preorder, inorder, 0, (int)preorder.size() - 1, 0);

      }
  };

int main()
{
    Solution solution;
    vector<int> given_pre = {3, 9, 20, 15, 7};
    vector<int> given_in = {9, 3, 15, 20, 7};
    TreeNode *expected_answer = new TreeNode(3);
    expected_answer->left = new TreeNode(9);
    expected_answer->right = new TreeNode(20);
    expected_answer->right->left = new TreeNode(15);
    expected_answer->right->right = new TreeNode(7);
    assert(*solution.buildTree(given_pre, given_in) == *expected_answer);

    return 0;
}
