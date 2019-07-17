//#993 Cousins in Binary Tree - https://leetcode.com/problems/cousins-in-binary-tree/
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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            int count_found = 0;
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                int cur_count = 0;
                if(cur_node->left != NULL && (cur_node->left->val == x || cur_node->left->val == y))
                    count_found++, cur_count++;
                if(cur_node->right != NULL && (cur_node->right->val == x || cur_node->right->val == y))
                    count_found++, cur_count++;
                if(cur_count == 2)
                    return false;
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }
            if(count_found == 2)
                return true;
            else if (count_found == 1)
                return false;
        }
        return false;

    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->left->right = new TreeNode(4);
    given_tree->right = new TreeNode(3);

    bool expected_answer = false;
    assert(solution.isCousins(given_tree, 2, 3) == expected_answer);

    return 0;
}
