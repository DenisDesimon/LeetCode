//#979 Distribute Coins in Binary Tree - https://leetcode.com/problems/distribute-coins-in-binary-tree/
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
    int coins(TreeNode* root, int& result)
    {
        if(root == NULL)
            return 0;
        int left = coins(root->left, result);
        int right = coins(root->right, result);
        result += abs(left) + abs(right);
        return left + right + root->val - 1;

    }
public:
    int distributeCoins(TreeNode* root) {
        int result = 0;
        coins(root, result);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(0);
    given_tree->left = new TreeNode(0);
    given_tree->right = new TreeNode(3);

    int expected_answer = 3;
    assert(solution.distributeCoins(given_tree) == expected_answer);

    return 0;
}
