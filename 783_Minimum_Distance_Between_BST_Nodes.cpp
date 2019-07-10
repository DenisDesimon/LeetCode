//#783 Minimum Distance Between BST Nodes - https://leetcode.com/problems/minimum-distance-between-bst-nodes/
#include <iostream>
#include <cassert>
#include <stack>
using namespace std;


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:

    int minDiffInBST(TreeNode* root) {
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
    TreeNode *given_tree = new TreeNode(4);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(6);
    given_tree->left->left = new TreeNode(1);
    given_tree->left->right = new TreeNode(3);

    int expected_answer = 1;
    assert(solution.minDiffInBST(given_tree) == expected_answer);

    return 0;
}
