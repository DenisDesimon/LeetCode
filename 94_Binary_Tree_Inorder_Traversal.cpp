//#94 Binary Tree Inorder Traversal - https://leetcode.com/problems/binary-tree-inorder-traversal/
#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> hash;
        while(root != NULL || !hash.empty())
        {
            while(root != NULL)
            {
                hash.push(root);
                root = root->left;
            }
            root = hash.top();
            result.push_back(hash.top()->val);
            hash.pop();
            root = root->right;
        }

        return result;

    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->right = new TreeNode(2);
    given_tree->right->left = new TreeNode(3);
    vector<int> expected_answer = {1, 3, 2};
    assert(solution.inorderTraversal(given_tree) == expected_answer);

    return 0;
}
