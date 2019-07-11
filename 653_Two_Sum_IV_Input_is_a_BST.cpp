//#653 Two Sum IV - Input is a BST - https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> nodes;
        vector<int> hash;
        while(root != NULL || !nodes.empty())
        {
            while(root != NULL)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            if(count(hash.begin(), hash.end(), k - root->val))
                    return true;
            hash.push_back(root->val);
            if(hash[0] + root->val > k)
                return false;
            root = root->right;

        }
        return false;
    }
};

int main()
{
    Solution solution;

    TreeNode* given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(3);
    given_tree->right = new TreeNode(6);
    given_tree->right->right = new TreeNode(7);
    given_tree->left->left = new TreeNode(2);
    given_tree->left->right = new TreeNode(4);

    bool expected_answer = true;
    int given_k = 9;
    assert(solution.findTarget(given_tree, given_k) == expected_answer);

    return 0;
}
