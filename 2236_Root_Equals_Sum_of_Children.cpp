//#2236 Root Equals Sum of Children - https://leetcode.com/problems/root-equals-sum-of-children/
#include <iostream>
#include <cassert>

using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool checkTree(TreeNode* root) {
        while(root->right->val != 0)
        {
            int temp = root->right->val;
            root->right->val = (unsigned)(root->left->val & temp) << 1;
            root->left->val = temp ^ root->left->val;
        }
        return root->val == root->left->val;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(10);
    given_tree->left = new TreeNode(4);
    given_tree->right = new TreeNode(6);
    bool expected_answer = true;
    assert(solution.checkTree(given_tree) == expected_answer);

    given_tree->val = 5;
    given_tree->left->val = 3;
    given_tree->right->val = 1;
    expected_answer = false;
    assert(solution.checkTree(given_tree) == expected_answer);

    return 0;
}
