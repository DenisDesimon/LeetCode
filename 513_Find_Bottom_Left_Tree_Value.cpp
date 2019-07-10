//#513 Find Bottom Left Tree Value - https://leetcode.com/problems/find-bottom-left-tree-value/
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        int result;
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                result = cur_node->val;
                nodes.push(cur_node->right);
                nodes.push(cur_node->left);
            }
        }
        return result;

    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(3);
    given_tree->left->left = new TreeNode(4);
    given_tree->right->left = new TreeNode(5);
    given_tree->right->right = new TreeNode(6);
    given_tree->right->left->left = new TreeNode(7);
    int expected_answer = 7;
    assert(solution.findBottomLeftValue(given_tree) == expected_answer);

    return 0;
}
