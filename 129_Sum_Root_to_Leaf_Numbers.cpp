//#129 Sum Root to Leaf Numbers - https://leetcode.com/problems/sum-root-to-leaf-numbers/
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
    void sum_path(TreeNode* root, int cur_path, int &sum)
    {
        if(root == NULL)
            return;
        cur_path = cur_path * 10 + root->val;
        if(root->left == NULL && root->right == NULL)
        {
            sum += cur_path;
            return;
        }
        sum_path(root->left, cur_path, sum);
        sum_path(root->right, cur_path, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int result;
        sum_path(root, 0, result);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(4);
    given_tree->left = new TreeNode(9);
    given_tree->right = new TreeNode(0);
    given_tree->left->left = new TreeNode(5);
    given_tree->left->right = new TreeNode(1);
    int expected_answer = 1026;
    assert(solution.sumNumbers(given_tree) == expected_answer);

    return 0;
}
