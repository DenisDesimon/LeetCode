//#968 Binary Tree Cameras - https://leetcode.com/problems/binary-tree-cameras/
#include <iostream>
#include <set>
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
    int result;
    set<TreeNode*> covered;
    void postorder(TreeNode* root, TreeNode* par){
        if(root != NULL)
        {
            postorder(root->left, root);
            postorder(root->right, root);

        if((par == NULL && !covered.count(root)) || !covered.count(root->left) || !covered.count(root->right))
        {
            result++;
            covered.insert(root);
            covered.insert(root->left);
            covered.insert(root->right);
            covered.insert(par);

        }

        }
    }
public:
    int minCameraCover(TreeNode* root) {
       covered.insert(NULL);
       result = 0;
       postorder(root, NULL);
       return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(0);
    given_tree->left = new TreeNode(0);
    given_tree->left->left = new TreeNode(0);
    given_tree->left->left->left = new TreeNode(0);
    given_tree->left->left->left->right = new TreeNode(0);

    int expected_answer = 2;
    assert(solution.minCameraCover(given_tree) == expected_answer);

    return 0;
}
