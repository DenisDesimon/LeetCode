//#145 Binary Tree Postorder Traversal - https://leetcode.com/problems/binary-tree-postorder-traversal/
#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> result;
        nodes.push(root);
        while(!nodes.empty())
        {
            auto cur_node = nodes.top();
            nodes.pop();
            if(cur_node == NULL)
                continue;
            result.insert(result.begin(), cur_node->val);
            nodes.push(cur_node->left);
            nodes.push(cur_node->right);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(1);
    given_tree->right = new TreeNode(2);
    given_tree->right->left = new TreeNode(3);
    vector<int> expected_answer = {3, 2, 1};
    assert(solution.postorderTraversal(given_tree) == expected_answer);

    return 0;
}
