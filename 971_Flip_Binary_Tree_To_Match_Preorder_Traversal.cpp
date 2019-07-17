//#971 Flip Binary Tree To Match Preorder Traversal - https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
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
  };

class Solution {
    void preorder(TreeNode* root, vector<int>& voyage, vector<int>& result, int& index){
        if(root == NULL)
            return;
        if(root->val != voyage[index++])
        {
            result.clear();
            result.push_back(-1);
            return;
        }
        if(index < (int)voyage.size() && root->left != NULL && root->left->val != voyage[index])
        {
            result.push_back(root->val);
            preorder(root->right, voyage, result, index);
            preorder(root->left, voyage, result, index);
        }
        else
        {
            preorder(root->left, voyage, result, index);
            preorder(root->right, voyage, result, index);
        }
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> result;
        int index = 0;
        preorder(root, voyage, result, index);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(3);

    vector<int> voyage = {1, 3, 2};
    vector<int> expected_answer = {1};
    assert(solution.flipMatchVoyage(given_tree, voyage) == expected_answer);

    return 0;
}
