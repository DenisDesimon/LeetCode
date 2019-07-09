//#337 House Robber III - https://leetcode.com/problems/house-robber-iii/
#include <iostream>
#include <unordered_map>
#include <algorithm>
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
    void post_order(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        if(root == NULL)
            return;
        post_order(root->left, dp);
        post_order(root->right, dp);
        dp[root] = max({dp[root->left] + dp[root->right],
                       (root->left ? dp[root->left->left] + dp[root->left->right] : 0) +
                       (root->right ? dp[root->right->left] + dp[root->right->right] : 0) +
                       root->val});

    }
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        dp[NULL] = 0;
        post_order(root, dp);
        return dp[root];
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(3);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(3);
    given_tree->left->right = new TreeNode(3);
    given_tree->right->right = new TreeNode(1);
    int expected_answer = 7;
    assert(solution.rob(given_tree) == expected_answer);

    return 0;
}
