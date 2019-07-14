//#589 N-ary Tree Preorder Traversal - https://leetcode.com/problems/n-ary-tree-preorder-traversal/
#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> preorder(Node* root) {
        stack<Node*> nodes;
        vector<int> result;
        if(root == NULL)
            return result;
        nodes.push(root);
        while(!nodes.empty())
        {
            auto cur_node = nodes.top();
            nodes.pop();
            if(cur_node == NULL)
                continue;
            result.push_back(cur_node->val);
            for(int i = (int)cur_node->children.size() - 1; i >= 0; i--)
            {
                nodes.push(cur_node->children[i]);
            }
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

    vector<int> expected_answer = {1, 3, 2, 4};
    assert(solution.preorder(given_node) == expected_answer);

    return 0;
}
