//#617 Merge Two Binary Trees - https://leetcode.com/problems/merge-two-binary-trees/
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
      TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
          if(t1 == NULL)
              return t2;
          else if(t2 == NULL)
              return t1;
          t1->val += t2->val;
          t1->left = mergeTrees(t1->left, t2->left);
          t1->right = mergeTrees(t1->right, t2->right);
          return t1;
      }
  };

int main()
{
    Solution solution;
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(3);
    t1->left->left = new TreeNode(5);
    t1->right = new TreeNode(2);

    TreeNode* t2 = new TreeNode(2);
    t2->left = new TreeNode(1);
    t2->left->right = new TreeNode(4);
    t2->right = new TreeNode(3);
    t2->right->right = new TreeNode(7);

    TreeNode* expected_answer = new TreeNode(3);
    expected_answer->left = new TreeNode(4);
    expected_answer->left->left = new TreeNode(5);
    expected_answer->left->right = new TreeNode(4);
    expected_answer->right = new TreeNode(5);
    expected_answer->right->right = new TreeNode(7);

    assert(*solution.mergeTrees(t1, t2) == *expected_answer);

    return 0;
}
