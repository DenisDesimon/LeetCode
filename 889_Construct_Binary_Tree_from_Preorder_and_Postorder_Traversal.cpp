//#889 Construct Binary Tree from Preorder and Postorder Traversal - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
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
    TreeNode* build_tree(vector<int>& preorder, vector<int>& postorder, int start, int end, int pre){
        if(start > end)
            return NULL;
        else if(start == end)
            return new TreeNode(postorder[start]);
        TreeNode* root = new TreeNode(preorder[pre]);
        int index = -1;
        for(int i = start; i <= end; i++)
        {
            if(postorder[i] == preorder[pre + 1])
            {
                index = i;
                break;
            }
        }
        root->left = build_tree(preorder, postorder, start, index, pre + 1);
        root->right = build_tree(preorder, postorder, index + 1, end - 1, index - start + 2 + pre);
        return root;

    }
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return build_tree(pre, post, 0, (int)pre.size() - 1, 0);

    }
};

int main()
{
    Solution solution;
    vector<int> given_pre = {1, 2, 4, 5, 3, 6, 7};
    vector<int> given_post = {4, 5, 2, 6, 7, 3, 1};
    TreeNode *expected_answer = new TreeNode(1);
    expected_answer->left = new TreeNode(2);
    expected_answer->right = new TreeNode(3);
    expected_answer->left->left = new TreeNode(4);
    expected_answer->left->right = new TreeNode(5);
    expected_answer->right->left = new TreeNode(6);
    expected_answer->right->right = new TreeNode(7);

    assert(*solution.constructFromPrePost(given_pre, given_post) == *expected_answer);

    return 0;
}
