//#783 Minimum Distance Between BST Nodes - https://leetcode.com/problems/minimum-distance-between-bst-nodes/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;


  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
    int min_distance = 1e9;
    vector<int> nodes;
public:
    int min_rec(TreeNode* root)
    {
        if(root->left != NULL)
        {
            min_rec(root->left);
            auto pos_left = upper_bound(nodes.begin(), nodes.end(), root->left->val);
            if(pos_left != nodes.end())
                min_distance = min(min_distance, *pos_left - root->left->val);
            if(pos_left != nodes.begin())
                min_distance = min(min_distance, root->left->val - *(pos_left - 1));
            nodes.insert(pos_left, root->left->val);
        }

        if(root->right != NULL)
        {
            min_rec(root->right);
            auto pos_right = upper_bound(nodes.begin(), nodes.end(), root->right->val);
            if(pos_right != nodes.end())
                min_distance = min(min_distance, *pos_right - root->right->val);
            if(pos_right != nodes.begin())
                min_distance = min(min_distance, root->right->val - *(pos_right - 1));
            nodes.insert(pos_right, root->right->val);

        }

        return min_distance;
    }
    int minDiffInBST(TreeNode* root) {
        nodes.push_back(root->val);
        return min_rec(root);
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(27);
    given_tree->right = new TreeNode(34);
    given_tree->right->right = new TreeNode(58);
    given_tree->right->right->left = new TreeNode(50);
    given_tree->right->right->left->right = new TreeNode(44);
    int expected_answer = 6;
    assert(solution.minDiffInBST(given_tree) == expected_answer);

    return 0;
}
