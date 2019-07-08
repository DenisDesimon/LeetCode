//#144 Binary Tree Preorder Traversal - https://leetcode.com/problems/binary-tree-preorder-traversal/
#include <iostream>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            auto cur_node = nodes.top();
            nodes.pop();
            if(cur_node == NULL)
                continue;
            result.push_back(cur_node->val);
            nodes.push(cur_node->right);
            nodes.push(cur_node->left);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(1);
    given_tree->right = new TreeNode(2);
    given_tree->right->left = new TreeNode(3);
    vector<int> expected_answer = {1, 2, 3};
    assert(solution.preorderTraversal(given_tree) == expected_answer);

    return 0;
}
