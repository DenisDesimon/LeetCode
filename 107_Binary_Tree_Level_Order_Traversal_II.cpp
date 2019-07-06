//#107 Binary Tree Level Order Traversal II - https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<vector<int>> result;
        nodes.push(root);
        while(!nodes.empty())
        {
            int size_node = (int)nodes.size();
            vector<int> sub_result;
            while(size_node--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                sub_result.push_back(cur_node->val);
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }
            if(sub_result.size() > 0)
                result.insert(result.begin(), sub_result);
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
    vector<vector<int>> expected_answer = {{15, 17}, {9, 20}, {3}};
    vector<vector<int>> result = solution.levelOrderBottom(given_tree);
    assert(expected_answer[0] == result[0] && expected_answer[1] == result[1] && expected_answer[2] == result[2]);

    return 0;
}
