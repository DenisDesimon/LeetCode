//#236 Lowest Common Ancestor of a Binary Tree - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
#include <iostream>
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
    TreeNode* result;
    bool find_nodes(TreeNode* cur, TreeNode* p, TreeNode* q)
    {
        if(cur == NULL)
            return false;
        bool left = find_nodes(cur->left, p, q);
        bool right = find_nodes(cur->right, p, q);
        bool mid = (cur == p || cur == q ? true : false);
        if(left + right + mid >= 2)
            result = cur;
        return left + right + mid > 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        result = NULL;
        find_nodes(root, p, q);
        return result;

    }
};

int main()
{
    Solution solution;
    TreeNode *given_q = new TreeNode(4);

    TreeNode *given_p = new TreeNode(5);
    given_p->left = new TreeNode(6);
    given_p->right = new TreeNode(2);
    given_p->right->left = new TreeNode(7);
    given_p->right->right = given_q;

    TreeNode *given_node = new TreeNode(3);
    given_node->left = given_p;
    given_node->right = new TreeNode(1);
    given_node->right->left = new TreeNode(0);
    given_node->right->right = new TreeNode(8);

    TreeNode*  expected_answer = given_p;
    assert(solution.lowestCommonAncestor(given_node, given_p, given_q) == expected_answer);

    return 0;
}
