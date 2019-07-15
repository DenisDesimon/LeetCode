//#863 All Nodes Distance K in Binary Tree - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> nodes;
        unordered_map<TreeNode*, bool> visited;
        visited[NULL] = true;
        vector<int> result;
        nodes.push(root);
        int level = K;
        bool is_found = false;
        while(!nodes.empty())
        {
            if(!level)
                break;
            int size_nodes = (int)nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                if(cur_node->val == target->val)
                    is_found = true;
                parent[cur_node->left] = cur_node;
                parent[cur_node->right] = cur_node;
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }
            if(is_found)
                level--;
        }
        while(!nodes.empty())
            nodes.pop();
        nodes.push(target);
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(visited[cur_node])
                    continue;
                visited[cur_node] = true;
                if(K == 0)
                {
                    result.push_back(cur_node->val);
                }
                else{
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
                nodes.push(parent[cur_node]);
                }
            }
            K--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* given_tree = new TreeNode(3);
    given_tree->left = new TreeNode(5);
    given_tree->right = new TreeNode(1);
    given_tree->left->left = new TreeNode(6);
    given_tree->left->right = new TreeNode(2);
    given_tree->right->left = new TreeNode(0);
    given_tree->right->right = new TreeNode(8);
    given_tree->left->right->left = new TreeNode(7);
    given_tree->left->right->right = new TreeNode(4);

    vector<int> expected_answer = {7, 4, 1};
    int given_k = 2;
    assert(solution.distanceK(given_tree, given_tree->left, given_k) == expected_answer);
    return 0;
}
