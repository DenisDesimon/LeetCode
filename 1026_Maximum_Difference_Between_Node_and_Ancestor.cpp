//#1026 Maximum Difference Between Node and Ancestor - https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/
#include <iostream>
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
    void find_max(TreeNode* root, int& min_val, int& max_val, int& result){
        if(root->left != NULL)
        {
            int min_left = root->left->val;
            int max_left = root->left->val;
            find_max(root->left, min_left, max_left, result);
            min_val = min(min_val, min_left);
            max_val = max(max_val, max_left);
        }
        if(root->right != NULL)
        {
            int min_right = root->right->val;
            int max_right = root->right->val;
            find_max(root->right, min_right, max_right, result);
            min_val = min(min_val, min_right);
            max_val = max(max_val, max_right);
        }
        result = max({result, abs(root->val - max_val), abs(root->val - min_val)});

    }
public:
    int maxAncestorDiff(TreeNode* root) {
        int result = 0, min_val = root->val, max_val = root->val;
        find_max(root, min_val, max_val, result);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(8);
    given_tree->left = new TreeNode(3);
    given_tree->left->left =new TreeNode(1);
    given_tree->left->right = new TreeNode(6);
    given_tree->left->right->left = new TreeNode(4);
    given_tree->left->right->left = new TreeNode(7);
    given_tree->right = new TreeNode(10);
    given_tree->right->right = new TreeNode(14);
    given_tree->right->right->left = new TreeNode(13);

    int expected_answer = 7;
    assert(solution.maxAncestorDiff(given_tree) == expected_answer);

    return 0;
}
