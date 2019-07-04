//#106 Construct Binary Tree from Inorder and Postorder Traversal - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int start, int end, int post) {
        if(start > end)
            return NULL;
        else if(start == end)
            return new TreeNode(postorder[post]);
        TreeNode* root = new TreeNode(postorder[post]);
        int index = -1;
        for(int i = start; i <= end; i++)
        {
            if(inorder[i] == postorder[post])
                index = i;
        }
 //(end - index) = number of members in the right branch
        root->left = buildTree(inorder, postorder, start, index - 1, post - (end - index) - 1);
        root->right = buildTree(inorder, postorder, index + 1, end, post - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, postorder, 0, (int)inorder.size() - 1, (int)inorder.size() - 1);

    }
};

int main()
{
    Solution solution;
    vector<int> given_in = {9, 3, 15, 20, 7};
    vector<int> given_post = {9, 15, 7, 20, 3};
    TreeNode *expected_answer = new TreeNode(3);
    expected_answer->left = new TreeNode(9);
    expected_answer->right = new TreeNode(20);
    expected_answer->right->left = new TreeNode(15);
    expected_answer->right->right = new TreeNode(7);
    assert(*solution.buildTree(given_in, given_post) == *expected_answer);

    return 0;
}
