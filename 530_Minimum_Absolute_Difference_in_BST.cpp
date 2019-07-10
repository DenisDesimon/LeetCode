//#530 Minimum Absolute Difference in BST - https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
  };

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> nodes;
        int result = INT_MAX;
        TreeNode* prev = NULL;
        while(root != NULL || !nodes.empty())
        {
            while(root != NULL)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            if(prev != NULL)
            result = min(result, root->val - prev->val);
            prev = root;
            root = root->right;
        }
        return result;

    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(4);
    given_tree->right = new TreeNode(7);

    int expected_answer = 1;
    assert(solution.getMinimumDifference(given_tree) == expected_answer);

    return 0;
}
