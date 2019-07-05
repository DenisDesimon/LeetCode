//#98 Validate Binary Search Tree - https://leetcode.com/problems/validate-binary-search-tree/
#include <iostream>
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
    bool isValidBST_rec(TreeNode* root, long long upper = LONG_LONG_MAX, long long lower = LONG_LONG_MIN) {
        if(root == NULL)
            return true;
        if((long long)root->val <= lower || (long long)root->val >= upper)
            return false;
        if(!isValidBST_rec(root->left, root->val, lower) || !isValidBST_rec(root->right, upper, root->val))
            return false;
        return true;
    }

    bool isValidBST(TreeNode* root){
        queue<TreeNode*> nodes;
        queue<long long> lowers, uppers;
        nodes.push(root), lowers.push(LONG_LONG_MIN), uppers.push(LONG_LONG_MAX);
        while(!nodes.empty())
        {
            auto cur_node = nodes.front();
            long long lower = lowers.front(), upper = uppers.front();
            nodes.pop(), lowers.pop(), uppers.pop();
            if(cur_node == NULL)
                continue;
            if((long long)cur_node->val <= lower || (long long)cur_node->val >= upper)
            return false;
            nodes.push(cur_node->left), lowers.push(lower), uppers.push(cur_node->val);
            nodes.push(cur_node->right), lowers.push(cur_node->val), uppers.push(upper);
        }
        return true;

    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(3);
    given_tree->left = new TreeNode(1);
    given_tree->right = new TreeNode(5);
    given_tree->left->left = new TreeNode(0);
    given_tree->left->right = new TreeNode(2);
    given_tree->right->left = new TreeNode(4);
    given_tree->right->right = new TreeNode(6);
    assert(solution.isValidBST(given_tree) == true);
    assert(solution.isValidBST_rec(given_tree) == true);

    given_tree = new TreeNode(2147483647);
    assert(solution.isValidBST(given_tree) == true);
    assert(solution.isValidBST_rec(given_tree) == true);

    return 0;
}
