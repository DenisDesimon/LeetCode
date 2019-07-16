//#958 Check Completeness of a Binary Tree - https://leetcode.com/problems/check-completeness-of-a-binary-tree/
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        bool has_NULL = false;
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                {
                    has_NULL = true;
                    continue;
                }
                if(has_NULL)
                    return false;
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(3);
    given_tree->left->left = new TreeNode(4);
    given_tree->left->right = new TreeNode(5);
    given_tree->right->left = new TreeNode(6);

    bool expected_answer = true;
    assert(solution.isCompleteTree(given_tree) == expected_answer);

    return 0;
}
