//#897 Increasing Order Search Tree - https://leetcode.com/problems/increasing-order-search-tree/
#include <iostream>
#include <stack>
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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> nodes;
        TreeNode* result = NULL;
        TreeNode* res = NULL;
        while(root != NULL || !nodes.empty())
        {
            while(root != NULL)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            if(result == NULL)
            {
                result = root;
                res = result;
            }
            else
            {
                res->right = new TreeNode(root->val);
                res = res->right;
            }
            root = root->right;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(3);
    given_tree->right = new TreeNode(6);
    given_tree->left->left = new TreeNode(2);
    given_tree->left->right = new TreeNode(4);
    given_tree->right->right = new TreeNode(8);

    TreeNode* expected_answer = new TreeNode(2);
    expected_answer->right = new TreeNode(3);
    expected_answer->right->right = new TreeNode(4);
    expected_answer->right->right->right = new TreeNode(5);
    expected_answer->right->right->right->right = new TreeNode(6);
    expected_answer->right->right->right->right->right = new TreeNode(8);

    assert(*solution.increasingBST(given_tree) == *expected_answer);

    return 0;
}
