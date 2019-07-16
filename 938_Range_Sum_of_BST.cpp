//#938 Range Sum of BST - https://leetcode.com/problems/range-sum-of-bst/
#include <iostream>
#include <stack>
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        stack<TreeNode*> nodes;
        int result = 0;
        while(root != NULL || !nodes.empty())
        {
            while(root != NULL)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            if(root->val >= L && root->val <= R)
            {
                result += root->val;
            }
            else if(root->val > R)
                break;
            root = root->right;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_node = new TreeNode(10);
    given_node->left = new TreeNode(5);
    given_node->right = new TreeNode(15);
    given_node->left->left = new TreeNode(3);
    given_node->left->right = new TreeNode(7);
    given_node->right->right = new TreeNode(18);

    int expected_answer = 32;
    int given_L = 7, given_R = 15;
    assert(solution.rangeSumBST(given_node, given_L, given_R) == expected_answer);

    return 0;
}
