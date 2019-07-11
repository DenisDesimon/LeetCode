//#563 Binary Tree Tilt - https://leetcode.com/problems/binary-tree-tilt/
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
        int findTilt(TreeNode* root, int& sum) {
            if(root == NULL)
                return 0;
            int left = findTilt(root->left, sum);
            int right = findTilt(root->right, sum);
            sum += abs(left - right);
            return left + right + root->val;

        }

public:
    int findTilt(TreeNode* root) {
        int sum = 0;
        findTilt(root, sum);
        return sum;

    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    given_tree->right= new TreeNode(3);
    int expected_answer = 1;

    assert(solution.findTilt(given_tree) == expected_answer);

    return 0;
}

