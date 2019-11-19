//#1261 Find Elements in a Contaminated Binary Tree - https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
#include <iostream>
#include <queue>
#include <unordered_set>
#include <cassert>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class FindElements {
    unordered_set<int> hash;
public:
    FindElements(TreeNode* root) {
        queue<TreeNode*> nodes;
        if(root != NULL)
        {
            root->val = 0;
            nodes.push(root);
        }
        while(!nodes.empty())
        {
            auto cur_node = nodes.front();
            nodes.pop();
            hash.insert(cur_node->val);
            if(cur_node->left != NULL)
            {
                cur_node->left->val = 2 * cur_node->val + 1;
                nodes.push(cur_node->left);
            }
            if(cur_node->right != NULL)
            {
                cur_node->right->val = 2 * cur_node->val + 2;
                nodes.push(cur_node->right);
            }
        }
    }

    bool find(int target) {
        return hash.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main()
{
    TreeNode* given_node = new TreeNode(-1);
    given_node->left = new TreeNode(-1);
    given_node->right = new TreeNode(-1);
    given_node->left->left = new TreeNode(-1);
    given_node->left->right = new TreeNode(-1);
    FindElements solution(given_node);
    int given_target = 3;
    assert(solution.find(given_target));

    given_target = 5;
    assert(!solution.find(given_target));

    return 0;
}
