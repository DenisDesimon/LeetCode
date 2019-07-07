//#110 Balanced Binary Tree - https://leetcode.com/problems/balanced-binary-tree/
#include <iostream>
#include <cassert>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
    int height(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = height(root->left);
        if(left == -1)
            return -1;
        int right = height(root->right);
        if(right == -1)
            return -1;
        if(abs(right - left) > 1)
            return -1;
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(3);
    given_tree->left = new TreeNode(9);
    given_tree->right = new TreeNode(20);
    given_tree->right->left = new TreeNode(15);
    given_tree->right->right = new TreeNode(17);
    bool expected_answer = true;
    assert(solution.isBalanced(given_tree) == expected_answer);

    return 0;
}

