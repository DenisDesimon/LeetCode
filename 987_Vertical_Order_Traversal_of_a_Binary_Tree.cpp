//#987 Vertical Order Traversal of a Binary Tree - https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
    void find_pos(TreeNode* root, int x, int y, vector<vector<int>>& field)
    {
        if(root == NULL)
            return;
        field.push_back({x, y, root->val});
        find_pos(root->left, x - 1, y + 1, field);
        find_pos(root->right, x + 1, y + 1, field);

    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        vector<vector<int>> field;
        find_pos(root, 0, 0, field);
        sort(field.begin(), field.end());
        int cur_x;
        vector<int> level;
        for(int i = 0; i < (int)field.size();)
        {
            cur_x = field[i][0];
            while(i < (int)field.size() && field[i][0] == cur_x)
            {
                level.push_back(field[i][2]);
                i++;
            }
            result.push_back(level);
            level.clear();
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(3);
    given_tree->left = new TreeNode(9);
    given_tree->left->right = new TreeNode(5);
    given_tree->right = new TreeNode(20);
    given_tree->right->left = new TreeNode(15);
    given_tree->right->right = new TreeNode(7);

    vector<vector<int>> expected_answer = {{9}, {3, 5, 15}, {20}, {7}};
    assert(solution.verticalTraversal(given_tree) == expected_answer);

    return 0;
}
