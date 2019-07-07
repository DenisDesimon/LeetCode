//#103 Binary Tree Zigzag Level Order Traversall - https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

  class Solution {
  public:
      vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          queue<TreeNode*> nodes;
          vector<vector<int>> result;
          nodes.push(root);
          int level = 0;
          while(!nodes.empty())
          {
              int size_nodes = (int)nodes.size();
              vector<int> sub_result;
              while(size_nodes--)
              {
                  auto cur_node = nodes.front();
                  nodes.pop();
                  if(cur_node == NULL)
                      continue;
                  nodes.push(cur_node->left);
                  nodes.push(cur_node->right);
                  if(level % 2 == 0)
                      sub_result.push_back(cur_node->val);
                  else
                      sub_result.insert(sub_result.begin(), cur_node->val);
              }
              result.push_back(sub_result);
              level++;
          }
          result.pop_back();
          return result;
      }
  };

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(3);
    given_tree->left = new TreeNode(9);
    given_tree->right = new TreeNode(20);
    given_tree->right->left = new TreeNode(15);
    given_tree->right->right = new TreeNode(17);
    vector<vector<int>> expected_answer = {{3}, {20, 9}, {15, 17}};
    vector<vector<int>> result = solution.zigzagLevelOrder(given_tree);
    assert(expected_answer[0] == result[0] && expected_answer[1] == result[1] && expected_answer[2] == result[2]);

    return 0;
}
