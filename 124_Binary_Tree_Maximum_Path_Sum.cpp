//#124 Binary Tree Maximum Path Sum - https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int result;
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        result = max(result, left + right + root->val);
        int length = max(left, right) + root->val;
        return length > 0 ? length : 0;
    }
public:
    int maxPathSum(TreeNode* root) {
        result = root->val;
        depth(root);
        return result;
    }
};
int main()
{
    Solution solution;
    TreeNode *given_node = new TreeNode(9);
    given_node->left = new TreeNode(6);
    given_node->right = new TreeNode(-3);
    given_node->right->left = new TreeNode(-6);
    given_node->right->right = new TreeNode(2);
    given_node->right->right->left = new TreeNode(2);
    given_node->right->right->left->left = new TreeNode(-6);
    given_node->right->right->left->right = new TreeNode(-6);
    int  expected_answer = 16;
    assert(solution.maxPathSum(given_node) == expected_answer);


    return 0;
}
