//#1110 Delete Nodes And Return Forest - https://leetcode.com/problems/delete-nodes-and-return-forest/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        queue<TreeNode*> nodes;
        vector<TreeNode*> result;
        nodes.push(root);
        if(count(to_delete.begin(), to_delete.end(), root->val))
        {
            if(root->left != NULL && !count(to_delete.begin(), to_delete.end(), root->left->val))
                result.push_back(root->left);
            if(root->right != NULL && !count(to_delete.begin(), to_delete.end(), root->right->val))
                result.push_back(root->right);
        }
        else
            result.push_back(root);
        while(!nodes.empty())
        {
            auto cur_node = nodes.front();
            nodes.pop();
            if(cur_node == NULL)
                continue;
            if(cur_node->left != NULL && count(to_delete.begin(), to_delete.end(), cur_node->left->val))
            {
                if(cur_node->left->left != NULL && !count(to_delete.begin(), to_delete.end(), cur_node->left->left->val))
                    result.push_back(cur_node->left->left);
                if(cur_node->left->right != NULL && !count(to_delete.begin(), to_delete.end(), cur_node->left->right->val))
                    result.push_back(cur_node->left->right);
                nodes.push(cur_node->left);
                cur_node->left = NULL;
            }
            if(cur_node->right != NULL && count(to_delete.begin(), to_delete.end(), cur_node->right->val))
            {
                if(cur_node->right->left != NULL && !count(to_delete.begin(), to_delete.end(), cur_node->right->left->val))
                    result.push_back(cur_node->right->left);
                if(cur_node->right->right != NULL && !count(to_delete.begin(), to_delete.end(), cur_node->right->right->val))
                    result.push_back(cur_node->right->right);
                nodes.push(cur_node->right);
                cur_node->right = NULL;
            }
            nodes.push(cur_node->left);
            nodes.push(cur_node->right);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->left->left =new TreeNode(4);
    given_tree->left->right = new TreeNode(3);
    vector<int> given_delete = {2, 3};

    vector<TreeNode*> expected_answer = {given_tree, given_tree->left->left};
    auto result = solution.delNodes(given_tree, given_delete);
    assert(*result[0] == *expected_answer[0] && *result[1] == *expected_answer[1]);

    return 0;
}
