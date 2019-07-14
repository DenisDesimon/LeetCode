//#429 N-ary Tree Level Order Traversal - https://leetcode.com/problems/n-ary-tree-level-order-traversal/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> nodes;
        vector<vector<int>> result;
        nodes.push(root);
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            vector<int> level_nodes;
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                level_nodes.push_back(cur_node->val);
                for(auto child : cur_node->children)
                {
                    nodes.push(child);
                }
            }
            if(!level_nodes.empty())
            result.push_back(level_nodes);
        }
        return result;

    }
};

int main()
{
    Solution solution;
    Node* given_node1 = new Node(3, {});
    Node* given_node2 = new Node(2, {});
    Node* given_node3 = new Node(4, {});
    Node* given_node = new Node(1, {given_node1, given_node2, given_node3});

    vector<vector<int>> expected_answer = {{1}, {3, 2, 4}};
    assert(solution.levelOrder(given_node) == expected_answer);
    return 0;
}
