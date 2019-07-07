//#113 Path Sum II - https://leetcode.com/problems/path-sum-ii/
#include <iostream>
#include <vector>
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
      vector<vector<int>> result;
      void pre_order(TreeNode* root, int cur_sum, int sum, vector<int> path)
      {
          if(root == NULL)
              return;
          cur_sum += root->val;
          path.push_back(root->val);
          if(root->left == NULL && root->right == NULL && cur_sum == sum)
          {
              result.push_back(path);
          }
          pre_order(root->left, cur_sum, sum, path);
          pre_order(root->right, cur_sum, sum, path);
      }
  public:
      vector<vector<int>> pathSum(TreeNode* root, int sum) {
          vector<int> path;
          pre_order(root, 0, sum, path);
          return result;
      }
  };

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(4);
    given_tree->right = new TreeNode(8);
    given_tree->left->left = new TreeNode(11);
    given_tree->left->left->left = new TreeNode(7);
    given_tree->left->left->right = new TreeNode(2);
    given_tree->right->left = new TreeNode(13);
    given_tree->right->right = new TreeNode(4);
    given_tree->right->right->right = new TreeNode(1);
    given_tree->right->right->left = new TreeNode(5);
    vector<vector<int>> expected_answer = {{5, 4, 11, 2}, {5, 8, 4, 5}};
    int given_sum = 22;
    vector<vector<int>> result = solution.pathSum(given_tree, given_sum);
    assert(result[0] == expected_answer[0] && result[1] == expected_answer[1]);

    return 0;
}
