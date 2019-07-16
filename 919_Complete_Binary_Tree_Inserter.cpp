//#919 Complete Binary Tree Inserter - https://leetcode.com/problems/complete-binary-tree-inserter/
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

class CBTInserter {
    vector<TreeNode*> nodes;
public:
    CBTInserter(TreeNode* root) {
        queue<TreeNode*> q_node;
        q_node.push(root);
        nodes.push_back(NULL);
        while(!q_node.empty())
        {
            auto cur_node = q_node.front();
            q_node.pop();
            if(cur_node == NULL)
                continue;
            nodes.push_back(cur_node);
            q_node.push(cur_node->left);
            q_node.push(cur_node->right);
        }


    }

    int insert(int v) {
        TreeNode* node = new TreeNode(v);
        int size_nodes = (int)nodes.size();
        if(size_nodes % 2 == 0)
            nodes[size_nodes / 2]->left = node;
        else
            nodes[size_nodes / 2]->right = node;
        nodes.push_back(node);
        return nodes[size_nodes / 2]->val;

    }

    TreeNode* get_root() {
        return nodes[1];
    }
};


int main()
{
    TreeNode* given_tree = new TreeNode(1);
    given_tree->left = new TreeNode(2);
    CBTInserter solution(given_tree);

    TreeNode* expected_answer = new TreeNode(1);
    expected_answer->left = new TreeNode(2);
    expected_answer->right = new TreeNode(3);
    expected_answer->left->left = new TreeNode(4);

    assert(solution.insert(3) == 1);
    assert(solution.insert(4) == 2);
    assert(*solution.get_root() == *expected_answer);

    return 0;
}
