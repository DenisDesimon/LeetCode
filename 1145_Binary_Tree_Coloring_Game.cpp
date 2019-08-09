//#1145 Binary Tree Coloring Game - https://leetcode.com/problems/binary-tree-coloring-game/
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
    int count_childs(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return count_childs(root->left) + count_childs(root->right) + 1;
    }
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if(n == 1)
        {
            if(count_childs(root->left) != count_childs(root->right))
                return true;
            else
                return false;
        }
        else
        {
            queue<TreeNode*> nodes;
            int size_red_nodes;
            nodes.push(root);
            TreeNode* x_node;
            while(!nodes.empty())
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                if(cur_node->val == x)
                {
                    x_node = cur_node;
                    break;
                }
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }
            int left_nodes_x = count_childs(x_node->left), right_nodes_x = count_childs(x_node->right);
            size_red_nodes = max(left_nodes_x, right_nodes_x);
            if(size_red_nodes > n - size_red_nodes)
                return true;
            size_red_nodes = left_nodes_x + right_nodes_x + 1;
            if(size_red_nodes > n - size_red_nodes)
                return false;
            else
                return true;
        }
    }
};

int main()
{
    Solution solution;
    TreeNode* given_node = new TreeNode(1);
    given_node->left = new TreeNode(2);
    given_node->right = new TreeNode(3);
    given_node->left->left  = new TreeNode(4);
    given_node->left->right = new TreeNode(5);
    given_node->right->left = new TreeNode(6);
    given_node->right->right = new TreeNode(7);
    given_node->left->left->left = new TreeNode(8);
    given_node->left->left->right = new TreeNode(9);
    given_node->left->right->left = new TreeNode(10);
    given_node->left->right->right = new TreeNode(11);
    bool expected_answer = true;
    int given_x = 3;
    int given_n = 11;
    assert(solution.btreeGameWinningMove(given_node, given_n, given_x) == expected_answer);

    return 0;
}
