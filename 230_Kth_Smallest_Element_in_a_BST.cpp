//#230 Kth Smallest Element in a BST - https://leetcode.com/problems/kth-smallest-element-in-a-bst/
#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
    void inorder(TreeNode* root, vector<int>& result){
        if(root == NULL)
            return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
public:
    int kthSmallest_rec(TreeNode* root, int k) {
        vector<int> result;
        inorder(root, result);
        return result[k - 1];
    }
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodes;
        while(true)
        {
            while(root != NULL)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            if(--k == 0)
                return root->val;
            root = root->right;
        }


    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(3);
    given_tree->left = new TreeNode(1);
    given_tree->right = new TreeNode(4);
    given_tree->left->right = new TreeNode(2);
    int given_k = 1;
    int expected_answer = 1;
    assert(solution.kthSmallest(given_tree, given_k) == expected_answer);
    assert(solution.kthSmallest_rec(given_tree, given_k) == expected_answer);

    return 0;
}
