//#133 Clone Graph - https://leetcode.com/problems/clone-graph/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cassert>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
    bool operator==(Node b)
    {
        queue<pair<Node*, Node*>> nodes;
        unordered_map<Node*, int> visited;
        nodes.push({this, &b});
        while(!nodes.empty())
        {
            auto cur_pair = nodes.front();
            nodes.pop();
            if(visited[cur_pair.first]++)
                continue;
            if(cur_pair.first->neighbors.size() != cur_pair.second->neighbors.size())
                return false;
            if(cur_pair.first->val != cur_pair.second->val)
                return false;
            for(int i = 0; i < (int)cur_pair.first->neighbors.size(); i++)
            {
                nodes.push({cur_pair.first->neighbors[i], cur_pair.second->neighbors[i]});
            }
        }
        return true;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> nodes;
        unordered_map<Node*, int> visited;
        unordered_map<Node*, Node*> created;
        nodes.push(node);
        while(!nodes.empty())
        {
            auto cur_node = nodes.front();
            nodes.pop();
            if(visited[cur_node]++)
                continue;
            if(!created.count(cur_node))
            {
                created[cur_node] = new Node(cur_node->val, {});
            }
            for(auto neighbor : cur_node->neighbors)
            {
                if(!created.count(neighbor))
                {
                    created[neighbor] = new Node(neighbor->val, {});
                }
                created[cur_node]->neighbors.push_back(created[neighbor]);
                nodes.push(neighbor);
            }

        }
        return created[node];

    }
};

int main()
{
    Solution solution;
    Node* given_Node1 = new Node(1, {});
    Node* given_Node2 = new Node(2, {});
    Node* given_Node3 = new Node(3, {});
    Node* given_Node4 = new Node(4, {});
    given_Node1->neighbors = {given_Node2, given_Node4};
    given_Node2->neighbors = {given_Node1, given_Node3};
    given_Node3->neighbors = {given_Node2, given_Node4};
    given_Node4->neighbors = {given_Node1, given_Node3};

    assert(*solution.cloneGraph(given_Node1) == *given_Node1);

    return 0;
}
