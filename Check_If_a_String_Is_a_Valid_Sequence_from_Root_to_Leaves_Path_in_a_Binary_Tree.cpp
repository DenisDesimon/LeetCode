//#Check If a String Is a Valid Sequence from Root to Leaves Path in a Binary Tree - https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/532/week-5/3315/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        queue<pair<TreeNode*, int>> nodes;
        nodes.push({root, 0});
        while(!nodes.empty())
        {
            auto cur_node = nodes.front();
            nodes.pop();
            if(cur_node.first == NULL)
                continue;
            if(cur_node.first->val == arr[cur_node.second])
            {
                if(cur_node.second == (int)arr.size() - 1)
                {
                    if(cur_node.first->left == NULL && cur_node.first->right == NULL)
                        return true;
                    continue;
                }
                nodes.push({cur_node.first->left, cur_node.second + 1});
                nodes.push({cur_node.first->right, cur_node.second + 1});
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_node = new TreeNode(0);
    given_node->left = new TreeNode(1);
    given_node->right = new TreeNode(0);
    given_node->left->left = new TreeNode(0);
    given_node->left->right = new TreeNode(1);
    given_node->left->left->right = new TreeNode(1);
    given_node->left->right->left = new TreeNode(0);
    given_node->left->right->right = new TreeNode(0);
    given_node->right->left = new TreeNode(0);
    vector<int> given_arr = {0, 1, 0, 1};
    bool expected_answer = true;
    assert(solution.isValidSequence(given_node, given_arr) == expected_answer);

    given_arr = {0, 1, 0};
    expected_answer = false;
    assert(solution.isValidSequence(given_node, given_arr) == expected_answer);

    return 0;
}
