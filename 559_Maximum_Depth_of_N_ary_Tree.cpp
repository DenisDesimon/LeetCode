//#559 Maximum Depth of N-ary Tree - https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
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
    int maxDepth(Node* root) {
        queue<Node*> nodes;
        int result = 0;
        if(root == NULL)
            return 0;
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
                for(auto child : cur_node->children)
                    nodes.push(child);
            }
            result++;
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

    int expected_answer = 2;
    assert(solution.maxDepth(given_node) == expected_answer);

    return 0;
}
