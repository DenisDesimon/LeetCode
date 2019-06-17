//#543 Diameter of Binary Tree - https://leetcode.com/problems/diameter-of-binary-tree/
#include <iostream>
#include <algorithm>
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
    int result;
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        result = max(result, left + right);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        result = 0;
        depth(root);
        return result;

    }
};


int main()
{
    Solution solution;
    TreeNode *given_node = new TreeNode(1);
    given_node->left = new TreeNode(2);
    given_node->right = new TreeNode(3);
    given_node->left->left = new TreeNode(4);
    given_node->left->right = new TreeNode(5);
    int  expected_answer = 3;
    assert(solution.diameterOfBinaryTree(given_node) == expected_answer);


    return 0;
}
