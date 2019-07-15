//#865 Smallest Subtree with all the Deepest Nodes - https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
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
    pair<TreeNode*, int> search(TreeNode* root){
        if(root == NULL)
            return {NULL, 0};
        auto left = search(root->left);
        auto right = search(root->right);
        if(left.second > right.second)
            return {left.first, left.second + 1};
        else if(left.second < right.second)
            return {right.first, right.second + 1};
        return {root, left.second + 1};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return search(root).first;

    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(3);
    given_tree->left = new TreeNode(5);
    given_tree->right = new TreeNode(1);
    given_tree->left->left = new TreeNode(6);
    given_tree->left->right = new TreeNode(2);
    given_tree->right->left = new TreeNode(0);
    given_tree->right->right = new TreeNode(8);
    given_tree->left->right->left = new TreeNode(7);
    given_tree->left->right->right = new TreeNode(4);

    TreeNode* expected_answer = new TreeNode(2);
    expected_answer->left = new TreeNode(7);
    expected_answer->right = new TreeNode(4);
    assert(*solution.subtreeWithAllDeepest(given_tree) == *expected_answer);

    return 0;
}
