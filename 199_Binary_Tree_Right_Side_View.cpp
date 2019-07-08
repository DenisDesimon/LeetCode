//#199 Binary Tree Right Side View - https://leetcode.com/problems/binary-tree-right-side-view/
#include <iostream>
#include <vector>
#include <cassert>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<int> result;
        nodes.push(root);
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            bool level_found = false;
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                if(!level_found)
                result.push_back(cur_node->val);
                level_found = true;
                nodes.push(cur_node->right);
                nodes.push(cur_node->left);
            }
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
    given_tree->left->right = new TreeNode(5);
    given_tree->right->right = new TreeNode(4);
    vector<int> expected_answer = {1, 3, 4};
    assert(solution.rightSideView(given_tree) == expected_answer);

    return 0;
}

