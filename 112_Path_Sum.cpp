//#112 Path Sum - https://leetcode.com/problems/path-sum/
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
    bool pre_order(TreeNode* root, int cur_sum, int sum)
    {
        if(root == NULL)
            return false;
        cur_sum += root->val;
        if(root->left == NULL && root->right == NULL && cur_sum == sum)
            return true;
        return pre_order(root->left, cur_sum, sum) || pre_order(root->right, cur_sum, sum);
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return pre_order(root, 0, sum);
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(4);
    given_tree->right = new TreeNode(8);
    given_tree->left->left = new TreeNode(11);
    given_tree->left->left->left = new TreeNode(7);
    given_tree->left->left->right = new TreeNode(2);
    given_tree->right->left = new TreeNode(13);
    given_tree->right->right = new TreeNode(4);
    given_tree->right->right->right = new TreeNode(1);
    bool expected_answer = true;
    int given_sum = 22;
    assert(solution.hasPathSum(given_tree, given_sum) == expected_answer);

    return 0;
}
