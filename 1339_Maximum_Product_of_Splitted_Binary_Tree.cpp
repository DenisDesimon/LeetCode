//#1339 Maximum Product of Splitted Binary Tree - https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/
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
    long long dfs(TreeNode* root, long long& result, long long& sum){
        if(root == NULL)
            return 0;
        long long sub = dfs(root->left, result, sum) + dfs(root->right, result, sum) + root->val;
        if(sum != 0)
            result = max(result, sub * (sum - sub));
        return sub;
    }
public:
    int maxProduct(TreeNode* root) {
        long long result = 0;
        long long sum = 0;
        sum = dfs(root, result, sum), dfs(root, result, sum);
        return result % (int)(1e9 + 7);
    }
};

int main()
{
    Solution solution;
    TreeNode* given_node = new TreeNode(1);
    given_node->right = new TreeNode(2);
    given_node->right->right = new TreeNode(4);
    given_node->right->left = new TreeNode(3);
    given_node->right->right->right = new TreeNode(5);
    given_node->right->right->left = new TreeNode(6);
    int expected_answer = 90;
    assert(solution.maxProduct(given_node) == expected_answer);

    given_node = new TreeNode(1);
    given_node->right = new TreeNode(1);
    expected_answer = 1;
    assert(solution.maxProduct(given_node) == expected_answer);

    return 0;
}
