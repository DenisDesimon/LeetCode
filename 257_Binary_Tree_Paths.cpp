//#257 Binary Tree Paths - https://leetcode.com/problems/binary-tree-paths/
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
    void paths(TreeNode* root, string cur_path, vector<string>& result){
        if(root == NULL)
            return;
        cur_path += "->" + to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            result.push_back(cur_path.substr(2));
            return;
        }
        paths(root->left, cur_path, result);
        paths(root->right, cur_path, result);

    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        paths(root, "", result);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(3);
    given_tree->left->right= new TreeNode(5);
    vector<string> expected_answer = {"1->2->5", "1->3"};

    assert(solution.binaryTreePaths(given_tree) == expected_answer);

    return 0;
}
