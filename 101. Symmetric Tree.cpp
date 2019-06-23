//#101 Symmetric Tree - https://leetcode.com/problems/symmetric-tree/
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
    bool is_mirror(TreeNode* nodel, TreeNode* noder){
        if(nodel == NULL && noder == NULL)
            return true;
        else if(nodel == NULL || noder == NULL)
            return false;
        return nodel->val == noder->val && is_mirror(nodel->left, noder->right) && is_mirror(nodel->right, noder->left);

    }
public:
    bool isSymmetric(TreeNode* root) {
        return is_mirror(root, root);
    }
};

int main()
{
    Solution solution;
    TreeNode *given_node = new TreeNode(1);
    given_node->left = new TreeNode(2);
    given_node->right = new TreeNode(2);
    given_node->left->left = new TreeNode(3);
    given_node->left->right = new TreeNode(4);
    given_node->right->left = new TreeNode(4);
    given_node->right->right = new TreeNode(3);
    bool  expected_answer = true;
    assert(solution.isSymmetric(given_node) == expected_answer);

    return 0;
}
