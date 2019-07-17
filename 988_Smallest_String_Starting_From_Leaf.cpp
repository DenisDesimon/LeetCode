//#988 Smallest String Starting From Leaf - https://leetcode.com/problems/smallest-string-starting-from-leaf/
#include <iostream>
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
    void find_path(TreeNode* root, string cur_path, string& result){
        if(root == NULL)
            return;
        cur_path.insert(cur_path.begin(), char('a' + root->val));
        if(root->left == NULL && root->right == NULL)
        {
            if(result.empty())
                result = cur_path;
            else
                result = result > cur_path ? cur_path : result;
            return;
        }
        find_path(root->left, cur_path, result);
        find_path(root->right, cur_path, result);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string result;
        find_path(root, "", result);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(0);
    given_tree->left = new TreeNode(1);
    given_tree->left->left = new TreeNode(3);
    given_tree->left->right = new TreeNode(4);
    given_tree->right = new TreeNode(2);
    given_tree->right->left = new TreeNode(3);
    given_tree->right->right = new TreeNode(3);

    string expected_answer = "dba";
    assert(solution.smallestFromLeaf(given_tree) == expected_answer);

    return 0;
}
