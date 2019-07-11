//#654 Maximum Binary Tree - https://leetcode.com/problems/maximum-binary-tree/
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
public:
    TreeNode* constructMaximumBinaryTree(vector<int> nums) {
        if(nums.empty())
            return NULL;
        auto iter = max_element(nums.begin(), nums.end());
        TreeNode* root = new TreeNode(*iter);
        if(nums.size() > 1)
        {
        root->left = constructMaximumBinaryTree(vector<int>(nums.begin(), iter));
        root->right = constructMaximumBinaryTree(vector<int>(iter + 1, nums.end()));
        }
        return root;

    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 2, 1, 6, 0, 5};
    TreeNode* expected_answer = new TreeNode(6);
    expected_answer->left = new TreeNode(3);
    expected_answer->right = new TreeNode(5);
    expected_answer->right->left = new TreeNode(0);
    expected_answer->left->right = new TreeNode(2);
    expected_answer->left->right->right = new TreeNode(1);

    assert(*solution.constructMaximumBinaryTree(given_nums) == *expected_answer);
    return 0;
}
