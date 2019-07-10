//#515 Find Largest Value in Each Tree Row - https://leetcode.com/problems/find-largest-value-in-each-tree-row/
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<int> result;
        nodes.push(root);
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            int cur_max = INT_MIN;
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                cur_max = max(cur_max, cur_node->val);
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }
            result.push_back(cur_max);
        }
        result.pop_back();
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(3);
    given_tree->right = new TreeNode(2);
    given_tree->left->left = new TreeNode(5);
    given_tree->right->left = new TreeNode(3);
    given_tree->right->right = new TreeNode(9);
    vector<int> expected_answer = {1, 3, 9};
    assert(solution.largestValues(given_tree) == expected_answer);

    return 0;
}
