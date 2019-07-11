//#652 Find Duplicate Subtrees - https://leetcode.com/problems/find-duplicate-subtrees/
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      bool operator==(TreeNode b)
      {
          bool Left = false, mid, Right = false;
          mid = val == b.val;
          if(left == NULL && b.left == NULL)
              Left = true;
          else if(left != NULL && b.left != NULL){
              Left = *left == *b.left;
          }
          if(right == NULL && b.right == NULL)
              Right = true;
          else if(right != NULL && b.right != NULL)
              Right = *right == *b.right;
          return Left + Right + mid > 2;

      }
  };

class Solution {
    string serialize(TreeNode* root, unordered_map<string, int>& count, vector<TreeNode*>& result)
    {
        if(root == NULL)
            return "";
        string serial = to_string(root->val) + "(" + serialize(root->left, count, result) + ")" + "(" + serialize(root->right, count, result) + ")";
        count[serial]++;
        if(count[serial] == 2)
            result.push_back(root);
        return serial;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> count;
        vector<TreeNode*> result;
        serialize(root, count, result);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(3);
    given_tree->right->left = new TreeNode(2);
    given_tree->right->left->left = new TreeNode(4);
    given_tree->right->right = new TreeNode(4);
    given_tree->left->left = new TreeNode(4);

    vector<TreeNode*> expected_answer = {given_tree->left->left, given_tree->left};
    auto result = solution.findDuplicateSubtrees(given_tree);
    assert(*result[0] == *expected_answer[0] && *result[1] == *expected_answer[1]);

    return 0;
}
