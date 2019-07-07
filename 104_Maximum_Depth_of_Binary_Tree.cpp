//#104 Maximum Depth of Binary Tree - https://leetcode.com/problems/maximum-depth-of-binary-tree/
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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> nodes;
        int result = 0;
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
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }
            result++;
        }
        result--;
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
    int expected_answer = 3;
    assert(solution.maxDepth(given_tree) == expected_answer);

    return 0;
}
