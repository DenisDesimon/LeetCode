//#606 Construct String from Binary Tree - https://leetcode.com/problems/construct-string-from-binary-tree/
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
public:
    string tree2str(TreeNode* t) {
        if(t == NULL)
            return "";
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        if(left.empty() && right.empty())
            return to_string(t->val);
        else if(right.empty())
            return to_string(t->val) +"(" + left + ")";
        return to_string(t->val) +"(" + left + ")"  +"(" + right + ")";
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(3);
    given_tree->left->left = new TreeNode(4);

    string expected_answer = "1(2(4))(3)";
    assert(solution.tree2str(given_tree) == expected_answer);

    return 0;
}
