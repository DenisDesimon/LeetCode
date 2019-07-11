//#572 Subtree of Another Tree - https://leetcode.com/problems/subtree-of-another-tree/
#include <iostream>
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
    bool traverse(TreeNode* s, TreeNode* t)
    {
        return s != NULL && (is_equal(s, t) || traverse(s->left, t) || traverse(s->right, t));
    }
    bool is_equal(TreeNode* s, TreeNode* t)
    {
        if(s == NULL && t == NULL)
            return true;
        else if(s == NULL || t == NULL)
            return false;
        return s->val == t->val && is_equal(s->left, t->left) && is_equal(s->right, t->right);
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s, t);

    }
};

int main()
{
    Solution solution;
    TreeNode* s = new TreeNode(3);
    s->left = new TreeNode(4);
    s->left->left = new TreeNode(1);
    s->left->left->left = new TreeNode(0);
    s->left->right = new TreeNode(2);
    s->right = new TreeNode(5);

    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(1);
    t->right = new TreeNode(2);

    bool expected_answer = false;
    assert(solution.isSubtree(s, t) == expected_answer);

    return 0;
}
