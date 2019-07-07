//#116 Populating Next Right Pointers in Each Node - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
#include <iostream>
#include <queue>
#include <cassert>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                    continue;
                if(cur_node->left)
                {
                cur_node->left->next = cur_node->right;
                if(cur_node->next)
                    cur_node->right->next = cur_node->next->left;
                }
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }
        }
        return root;
    }
};

int main()
{
    Solution solution;
    Node* left = new Node(2, NULL, NULL, NULL);
    Node* right = new Node(3, NULL, NULL, NULL);
    Node* given_tree = new Node(1, left, right, NULL);
    solution.connect(given_tree);
    assert(left->next == right);

    return 0;
}
