//#872 Leaf-Similar Treesm - https://leetcode.com/problems/leaf-similar-trees/
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
  };

class Solution {
    void find_leaves(TreeNode* root, vector<int>& leaves){
        if(root->left == NULL && root->right == NULL)
        {
            leaves.push_back(root->val);
            return;
        }
        if(root->left != NULL)
            find_leaves(root->left, leaves);
        if(root->right != NULL)
            find_leaves(root->right, leaves);

    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        find_leaves(root1, leaves1);
        find_leaves(root2, leaves2);
        return leaves1 == leaves2;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_node1 = new TreeNode(3);
    given_node1->left = new TreeNode(5);
    given_node1->right = new TreeNode(1);
    given_node1->right->left = new TreeNode(-6);
    given_node1->right->right = new TreeNode(2);

    TreeNode *given_node2 = new TreeNode(5);
    given_node2->left = new TreeNode(5);
    given_node2->right = new TreeNode(4);
    given_node2->right->left = new TreeNode(-6);
    given_node2->right->right = new TreeNode(2);
    bool  expected_answer = true;
    assert(solution.leafSimilar(given_node1, given_node2) == expected_answer);

    return 0;
}
