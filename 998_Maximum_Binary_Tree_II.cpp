//#998 Maximum Binary Tree II - https://leetcode.com/problems/maximum-binary-tree-ii/
#include <iostream>
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
    TreeNode* insert(TreeNode* root, int val){
        if(root->val < val)
        {
            TreeNode* swap = new TreeNode(val);
            swap->left = root;
            return swap;
        }
        if(root->right == NULL)
        {
            root->right = new TreeNode(val);
            return root;
        }
        else
            root->right = insert(root->right, val);
        return root;
    }
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        return insert(root, val);

    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(4);
    given_tree->left = new TreeNode(1);
    given_tree->right = new TreeNode(3);
    given_tree->right->left = new TreeNode(2);

    TreeNode* expected_answer = new TreeNode(5);
    expected_answer->left = new TreeNode(4);
    expected_answer->left->left =new TreeNode(1);
    expected_answer->left->right = new TreeNode(3);
    expected_answer->left->right->left = new TreeNode(2);

    int given_val = 5;
    assert(*solution.insertIntoMaxTree(given_tree, given_val) == *expected_answer);

    return 0;
}
