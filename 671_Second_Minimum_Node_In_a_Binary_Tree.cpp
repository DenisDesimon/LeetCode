//#671 Second Minimum Node In a Binary Tree - https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL)
            return -1;
        stack<TreeNode*> nodes;
        TreeNode* first = NULL;
        long long result = LONG_LONG_MAX;
        nodes.push(root);
        first = root;
        while(!nodes.empty())
        {
            root = nodes.top();
            nodes.pop();
            if(root == NULL)
                continue;
            if(first->val != root->val)
            {
                result = min(result, (long long)root->val);
            }
            nodes.push(root->left);
            nodes.push(root->right);
        }
        return result == LONG_LONG_MAX ? -1 : (int)result;

    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(8);
    given_tree->right = new TreeNode(5);
    int expected_answer = 8;
    assert(solution.findSecondMinimumValue(given_tree) == expected_answer);

    given_tree = new TreeNode(2);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(5);
    given_tree->right->left = new TreeNode(5);
    given_tree->right->right = new TreeNode(7);
    expected_answer = 5;
    assert(solution.findSecondMinimumValue(given_tree) == expected_answer);

    return 0;
}
