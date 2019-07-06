//#637 Average of Levels in Binary Tree - https://leetcode.com/problems/average-of-levels-in-binary-tree/
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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<double> result;
        nodes.push(root);
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            double sum = 0, level = 0;
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                sum += cur_node->val, level++;
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }
            result.push_back(sum / level);
        }
        result.pop_back();
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
    given_tree->right->right = new TreeNode(7);
    vector<double> expected_answer = {3, 14.5, 11};
    assert(solution.averageOfLevels(given_tree) == expected_answer);

    return 0;
}
