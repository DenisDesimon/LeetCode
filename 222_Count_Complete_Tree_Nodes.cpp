//#222 Count Complete Tree Nodes - https://leetcode.com/problems/count-complete-tree-nodes/
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
    int countNodes(TreeNode* root) {
        queue<TreeNode*> nodes;
        int result = 0;
        nodes.push(root);
        int level = 0;
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    return result;
                if(cur_node->left != NULL)
                {
                    result += (1 << level);
                    nodes.push(cur_node->left);
                    nodes.push(cur_node->right);
                    while(size_nodes){
                        auto cur_node2 = nodes.front();
                        nodes.pop();
                        nodes.push(cur_node2->left);
                        nodes.push(cur_node2->right);
                        size_nodes--;
                    }
                    result--;
                }
                result++;
            }
            level++;
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
    given_tree->left->right = new TreeNode(5);
    given_tree->right->left = new TreeNode(6);
    int expected_answer = 6;
    assert(solution.countNodes(given_tree) == expected_answer);

    return 0;
}

