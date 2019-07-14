//#700 Search in a Binary Search Tree - https://leetcode.com/problems/search-in-a-binary-search-tree/
#include <iostream>
#include <stack>
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
    TreeNode* searchBST(TreeNode* root, int val) {
        stack<TreeNode*> nodes;
        nodes.push(root);
        while(root != NULL || !nodes.empty())
        {
            while(root != NULL)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            if(root->val == val)
                return root;
            root = root->right;
        }
        return NULL;

    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(4);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(7);
    given_tree->left->left = new TreeNode(1);
    given_tree->left->right = new TreeNode(3);

    int given_val = 2;
    TreeNode* expected_answer = new TreeNode(2);
    expected_answer->left = new TreeNode(1);
    expected_answer->right = new TreeNode(3);
    assert(*solution.searchBST(given_tree, given_val) == *expected_answer);

    return 0;
}
