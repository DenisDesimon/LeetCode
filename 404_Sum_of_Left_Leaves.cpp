//#404 Sum of Left Leaves - https://leetcode.com/problems/sum-of-left-leaves/
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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                if(cur_node->left != NULL && cur_node->left->left == NULL && cur_node->left->right == NULL)
                {
                    result += cur_node->left->val;
                    nodes.push(cur_node->right);
                    continue;
                }
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(3);
    given_tree->left = new TreeNode(9);
    given_tree->right = new TreeNode(20);
    given_tree->right->left = new TreeNode(15);
    given_tree->right->right = new TreeNode(17);
    int expected_answer = 24;
    assert(solution.sumOfLeftLeaves(given_tree) == expected_answer);

    return 0;
}
