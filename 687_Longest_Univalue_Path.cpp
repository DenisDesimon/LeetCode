//#687 Longest Univalue Path - https://leetcode.com/problems/longest-univalue-path/
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
    int longestUnivaluePath(TreeNode* root, int& result) {
        if(root == NULL)
            return 0;
        int left = longestUnivaluePath(root->left, result);
        int right = longestUnivaluePath(root->right, result);
        int cur_left = 0, cur_right = 0;
        if(root->left != NULL && root->val == root->left->val)
        {
            cur_left += left + 1;
        }
        if(root->right != NULL && root->val == root->right->val)
        {
            cur_right += right + 1;
        }
        result = max(result, cur_left + cur_right);
        return max(cur_left, cur_right);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        int result = 0;
        longestUnivaluePath(root, result);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(4);
    given_tree->right = new TreeNode(5);
    given_tree->left->left = new TreeNode(1);
    given_tree->left->right = new TreeNode(1);
    given_tree->right->right = new TreeNode(5);

    int expected_answer = 2;
    assert(solution.longestUnivaluePath(given_tree) == expected_answer);

    return 0;
}
