//#965 Univalued Binary Tree - https://leetcode.com/problems/univalued-binary-tree/
#include <iostream>
#include <queue>
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
    bool isUnivalTree(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        int value = root->val;
        while(!nodes.empty())
        {
            auto cur_node = nodes.front();
            nodes.pop();
            if(cur_node == NULL)
                continue;
            if(cur_node->val != value)
                return false;
            nodes.push(cur_node->left);
            nodes.push(cur_node->right);
        }
        return true;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(1);
    given_tree->right = new TreeNode(1);
    given_tree->left->left = new TreeNode(1);
    given_tree->left->right = new TreeNode(1);
    given_tree->right->left = new TreeNode(1);

    bool expected_answer = true;
    assert(solution.isUnivalTree(given_tree) == expected_answer);

    return 0;
}
