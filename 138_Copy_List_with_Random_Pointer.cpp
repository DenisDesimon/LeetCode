//#138 Copy List with Random Pointer - https://leetcode.com/problems/copy-list-with-random-pointer/
#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
    bool operator ==(Node b){
              if((b.next == NULL && next == NULL) || (b.random == NULL && random == NULL))
                  return val == b.val;
              else if(b.next == NULL || next == NULL || b.random == NULL || random == NULL)
                  return false;
              return val == b.val && random->val == b.random->val && *next == *b.next;
          }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hashmap;
        hashmap[NULL] = NULL;
        Node* cur = head;
        while(cur != NULL)
        {
            if(!hashmap.count(cur))
                hashmap[cur] = new Node(cur->val, NULL, NULL);
            if(!hashmap.count(cur->random))
                hashmap[cur->random] = new Node(cur->random->val, NULL, NULL);
            if(!hashmap.count(cur->next))
                hashmap[cur->next] = new Node(cur->next->val, NULL, NULL);
            hashmap[cur]->next = hashmap[cur->next];
            hashmap[cur]->random = hashmap[cur->random];
            cur = cur->next;
        }
        return hashmap[head];
    }
};

int main()
{
    Solution solution;
    Node* given_node = new Node(1, NULL, NULL);
    given_node->next = new Node(2, NULL, given_node);
    given_node->next->next = new Node(3, NULL, given_node->next);
    given_node->next->next->next = new Node(4, NULL, given_node);
    given_node->next->next->next->next = new Node(5, NULL, given_node->next->next);

    assert(*solution.copyRandomList(given_node) == *given_node);

    return 0;
}
