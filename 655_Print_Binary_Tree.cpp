//#655 Print Binary Tree - https://leetcode.com/problems/print-binary-tree/
#include <iostream>
#include <queue>
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
    int height_tree(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        return max(height_tree(root->left), height_tree(root->right)) + 1;
    }
    void printTree(TreeNode *root, vector<vector<string>>& result, int left, int right, int cur_lvl){
        if(root == NULL)
            return;
        int mid = (left + right) / 2;
        result[cur_lvl][mid] = to_string(root->val);
        printTree(root->left, result, left, mid, cur_lvl + 1);
        printTree(root->right, result, mid + 1, right, cur_lvl + 1);

    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = height_tree(root);
        vector<vector<string>> result(height, vector<string>((1 << height) - 1, ""));
        printTree(root, result, 0, (int)result[0].size() - 1, 0);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(3);
    given_tree->left->right = new TreeNode(4);

    vector<vector<string>> expected_answer = {{"", "", "", "1", "", "", ""},
                                              {"", "2", "", "", "", "3", ""},
                                              {"", "", "4", "", "", "", ""}};
    assert(solution.printTree(given_tree) == expected_answer);

    return 0;
}
