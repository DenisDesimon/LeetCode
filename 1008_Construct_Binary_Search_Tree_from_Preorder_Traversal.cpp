//#1008 Construct Binary Search Tree from Preorder Traversal - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
#include <iostream>
#include <vector>
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
    TreeNode* buildtree(vector<int>& preorder, int start, int end){
        if(start > end)
            return NULL;
        if(start == end)
            return new TreeNode(preorder[start]);
        TreeNode* root = new TreeNode(preorder[start]);
        int index = end + 1;
        for(int i = start; i <= end; i++)
        {
            if(preorder[start] < preorder[i])
               {
                    index = i;
                    break;
                }
        }
        root->left = buildtree(preorder, start + 1, index - 1);
        root->right = buildtree(preorder, index, end);
        return root;

    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildtree(preorder, 0, (int)preorder.size() - 1);
    }
};

int main()
{
    Solution solution;
    vector<int> given_preorder = {8, 5, 1, 7, 10, 12};

    TreeNode* expected_answer = new TreeNode(8);
    expected_answer->left = new TreeNode(5);
    expected_answer->left->left =new TreeNode(1);
    expected_answer->left->right = new TreeNode(7);
    expected_answer->right = new TreeNode(10);
    expected_answer->right->right = new TreeNode(12);

    assert(*solution.bstFromPreorder(given_preorder) == *expected_answer);

    return 0;
}
