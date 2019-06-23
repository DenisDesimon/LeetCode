//#108 Convert Sorted Array to Binary Search Tree - https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


  //Definition for a binary tree node.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = (int)nums.size();
        if(size == 0)
            return NULL;
        TreeNode* cur_node = new TreeNode(nums[size/2]);
        if(size > 1)
        {
            vector<int> left(nums.begin(), nums.begin() + size/2);
            vector<int> right(nums.begin() + size/2 + 1, nums.end());
            cur_node->left = sortedArrayToBST(left);
            cur_node->right = sortedArrayToBST(right);
        }
        return cur_node;

    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {-10, -3, 0, 5, 9};
    TreeNode *expected_answer = new TreeNode(0);
    expected_answer->left = new TreeNode(-3);
    expected_answer->right = new TreeNode(9);
    expected_answer->left->left = new TreeNode(-10);
    expected_answer->right->left = new TreeNode(5);
    assert(*solution.sortedArrayToBST(given_nums) == *expected_answer);


    return 0;
}
