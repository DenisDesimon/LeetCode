//#501 Find Mode in Binary Search Tree - https://leetcode.com/problems/find-mode-in-binary-search-tree/
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
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> result;
        int cur_mod = 0, max_mod = 0, prev;
        if(root != NULL)
            prev = root->val;
        while(root != NULL || !nodes.empty())
        {
            while(root != NULL)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            if(root->val == prev)
                cur_mod++;
            else
            {
                cur_mod = 1;
                prev = root->val;
            }
            if(cur_mod > max_mod)
            {
                result.clear();
                result.push_back(root->val);
                max_mod = cur_mod;
            }
            else if(cur_mod == max_mod)
                result.push_back(root->val);
            root = root->right;

        }

        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(6);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(8);
    given_tree->left->left = new TreeNode(0);
    given_tree->left->right = new TreeNode(4);
    given_tree->left->right->left = new TreeNode(2);
    given_tree->left->right->right = new TreeNode(6);
    given_tree->right->left = new TreeNode(7);
    given_tree->right->right = new TreeNode(9);

    vector<int> expected_answer = {2, 6};
    assert(solution.findMode(given_tree) == expected_answer);

    return 0;
}
