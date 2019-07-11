//#623 Add One Row to Tree - https://leetcode.com/problems/add-one-row-to-tree/
#include <iostream>
#include <queue>
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        if(d == 1)
        {
            TreeNode* left = new TreeNode(v);
            left->left = root;
            return left;
        }
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                if(d == 2)
                {
                    TreeNode* left = new TreeNode(v);
                    left->left = cur_node->left;
                    TreeNode* right = new TreeNode(v);
                    right->right = cur_node->right;
                    cur_node->left = left, cur_node->right = right;
                }
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);

            }
            if(d == 2)
                break;
            d--;
        }
        return root;
    }
};

int main()
{
    Solution solution;
    int given_v = 1, given_d = 2;
    TreeNode* given_tree = new TreeNode(4);
    given_tree->left = new TreeNode(2);
    given_tree->left->left = new TreeNode(3);
    given_tree->left->right = new TreeNode(1);
    given_tree->right = new TreeNode(6);
    given_tree->right->left = new TreeNode(5);

    TreeNode* expected_answer = new TreeNode(4);
    expected_answer->left = new TreeNode(given_v);
    expected_answer->left->left = new TreeNode(2);
    expected_answer->left->left->left = new TreeNode(3);
    expected_answer->left->left->right = new TreeNode(1);
    expected_answer->right = new TreeNode(given_v);
    expected_answer->right->right = new TreeNode(6);
    expected_answer->right->right->left = new TreeNode(5);

    assert(*solution.addOneRow(given_tree, given_v, given_d) == *expected_answer);

    return 0;
}
