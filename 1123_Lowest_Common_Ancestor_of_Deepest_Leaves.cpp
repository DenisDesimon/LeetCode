#include <iostream>
#include <unordered_map>
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
    int depth(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL)
            return NULL;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left == right)
            return root;
        if(left > right)
            return lcaDeepestLeaves(root->left);
        return lcaDeepestLeaves(root->right);
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(3);
    given_tree->left->left =new TreeNode(4);
    given_tree->left->right = new TreeNode(5);

    TreeNode* expected_answer = new TreeNode(2);
    expected_answer->left = new TreeNode(4);
    expected_answer->right = new TreeNode(5);

    assert(*solution.lcaDeepestLeaves(given_tree) == *expected_answer);

    return 0;
}
