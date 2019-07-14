//#669 Trim a Binary Search Tree - https://leetcode.com/problems/trim-a-binary-search-tree/
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL)
            return NULL;
        if(root->val > R)
            return trimBST(root->left, L, R);
        if(root->val < L)
            return trimBST(root->right, L, R);
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;

    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(3);
    given_tree->left = new TreeNode(0);
    given_tree->right = new TreeNode(4);
    given_tree->left->right = new TreeNode(2);
    given_tree->left->right->left = new TreeNode(1);

    TreeNode* expected_answer = new TreeNode(3);
    expected_answer->left = new TreeNode(2);
    expected_answer->left->left = new TreeNode(1);

    int given_L = 1, given_R = 3;
    assert(*solution.trimBST(given_tree, given_L, given_R) == *expected_answer);

    return 0;
}
