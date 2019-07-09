//#437 Path Sum III - https://leetcode.com/problems/path-sum-iii/
#include <iostream>
#include <vector>
#include <algorithm>
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
    void path(TreeNode* root, vector<int> &prefix_sum, int &result, int target){
        if(root == NULL)
            return;
        int cur_sum = 0;
        if(prefix_sum.size() > 0)
        cur_sum += prefix_sum[prefix_sum.size() - 1];
        cur_sum += root->val;
        prefix_sum.push_back(cur_sum);
        result += count(prefix_sum.begin(), prefix_sum.end() - 1, cur_sum - target);
        if(cur_sum == target)
            result++;
        path(root->left, prefix_sum, result, target);
        path(root->right, prefix_sum, result, target);
        prefix_sum.erase(prefix_sum.end() - 1);

    }
public:
    int pathSum(TreeNode* root, int sum) {
        vector<int> prefix_sum;
        int result = 0;
        path(root, prefix_sum, result, sum);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(0);
    given_tree->right = new TreeNode(1);
    given_tree->left->left= new TreeNode(1);
    given_tree->left->right = new TreeNode(2);
    given_tree->left->left->left= new TreeNode(0);
    given_tree->left->left->right= new TreeNode(1);
    given_tree->left->right->left = new TreeNode(-1);
    given_tree->left->right->right = new TreeNode(0);
    given_tree->right->left = new TreeNode(0);
    given_tree->right->right = new TreeNode(-1);
    given_tree->right->left->left = new TreeNode(-1);
    given_tree->right->left->right = new TreeNode(0);
    given_tree->right->right->left = new TreeNode(1);
    given_tree->right->right->right = new TreeNode(0);
    int expected_answer = 13;
    int given_target = 2;
    assert(solution.pathSum(given_tree, given_target) == expected_answer);

    return 0;
}
