//#951 Flip Equivalent Binary Trees - https://leetcode.com/problems/flip-equivalent-binary-trees/
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
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return true;
        else if(root1 == NULL || root2 == NULL)
            return false;
        return (root1->val == root2->val) &&
                ((flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
                 (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left)));
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree1 = new TreeNode(1);
    given_tree1->left = new TreeNode(2);
    given_tree1->left->left = new TreeNode(4);
    given_tree1->left->right = new TreeNode(5);
    given_tree1->left->right->left = new TreeNode(7);
    given_tree1->left->right->right = new TreeNode(8);
    given_tree1->right = new TreeNode(3);
    given_tree1->right->left = new TreeNode(6);

    TreeNode* given_tree2 = new TreeNode(1);
    given_tree2->left = new TreeNode(3);
    given_tree2->left->right = new TreeNode(6);
    given_tree2->right = new TreeNode(2);
    given_tree2->right->left = new TreeNode(4);
    given_tree2->right->right = new TreeNode(5);
    given_tree2->right->right->left = new TreeNode(8);
    given_tree2->right->right->right = new TreeNode(7);

    bool expected_answer = true;
    assert(solution.flipEquiv(given_tree1, given_tree2) == expected_answer);

    return 0;
}
