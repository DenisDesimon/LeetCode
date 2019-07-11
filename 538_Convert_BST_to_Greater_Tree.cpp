//#538 Convert BST to Greater Tree - https://leetcode.com/problems/convert-bst-to-greater-tree/
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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> nodes;
        TreeNode* prev = NULL;
        TreeNode* node = root;
        while(node != NULL || !nodes.empty())
        {
            while(node != NULL)
            {
                nodes.push(node);
                node = node->right;
            }
            node = nodes.top();
            nodes.pop();
            if(prev != NULL)
                node->val += prev->val;
            prev = node;
            node = node->left;
        }
        return root;

    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(2);
    given_tree->right= new TreeNode(13);

    TreeNode* expected_answer = new TreeNode(18);
    expected_answer->left = new TreeNode(20);
    expected_answer->right = new TreeNode(13);

    assert(*solution.convertBST(given_tree) == *expected_answer);

    return 0;
}
