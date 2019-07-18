//#1022 Sum of Root To Leaf Binary Numbers - https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/
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
    void find_path(TreeNode* root, int cur_path, int& result){
        if(root == NULL)
            return;
        cur_path <<= 1;
        if(root->val == 1)
            cur_path |= 1;
        if(root->left == NULL && root->right == NULL)
        {
            result += cur_path;
            return;
        }
        find_path(root->left, cur_path, result);
        find_path(root->right, cur_path, result);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        int result = 0;
        find_path(root, 0, result);
        return result;
    }

};


int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(0);
    given_tree->left->left =new TreeNode(0);
    given_tree->left->right = new TreeNode(1);
    given_tree->right = new TreeNode(1);
    given_tree->right->left = new TreeNode(0);
    given_tree->right->right = new TreeNode(1);

    int expected_answer = 22;
    assert(solution.sumRootToLeaf(given_tree) == expected_answer);

    return 0;
}

