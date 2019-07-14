//#662 Maximum Width of Binary Tree - https://leetcode.com/problems/maximum-width-of-binary-tree/
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> nodes;
        int result = 1;
        nodes.push({root, 0});
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            int left = -1, right = -1;
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(left == -1)
                {
                    left = cur_node.second;
                }
                right = cur_node.second;
                cur_node.second -= left;
                if(cur_node.first->left != NULL)
                    nodes.push({cur_node.first->left, cur_node.second * 2});
                if(cur_node.first->right != NULL)
                    nodes.push({cur_node.first->right, cur_node.second * 2 + 1});
            }
                result = max(result, (int)(right - left + 1));
        }
        return (int)result;

    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(3);
    given_tree->right = new TreeNode(2);
    given_tree->left->left = new TreeNode(5);
    given_tree->left->right = new TreeNode(3);
    given_tree->right->right = new TreeNode(9);

    int expected_answer = 4;
    assert(solution.widthOfBinaryTree(given_tree) == expected_answer);

    return 0;
}
