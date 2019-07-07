//#117 Populating Next Right Pointers in Each Node II - https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
#include <iostream>
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
      Node *cur_lower = NULL, *head = NULL, *cur = root;
      while(cur)
      {
          while(cur)
          {
              if(cur->left)
              {
                  if(cur_lower == NULL)
                      head = cur->left;
                  else
                      cur_lower->next = cur->left;

                  cur_lower = cur->left;
              }

              if(cur->right)
              {
                  if(cur_lower == NULL)
                      head = cur->right;
                  else
                      cur_lower->next = cur->right;

                  cur_lower = cur->right;
              }
              cur = cur->next;
          }
          cur = head;
          head = cur_lower = NULL;
      }
      return root;

    }
};

int main()
{
    Solution solution;
    Node* left_left = new Node(4, NULL, NULL, NULL);
    Node* left = new Node(2, left_left, NULL, NULL);
    Node* right_right = new Node(5, NULL, NULL, NULL);
    Node* right = new Node(3, NULL, right_right, NULL);
    Node* given_tree = new Node(1, left, right, NULL);
    solution.connect(given_tree);
    assert(left->next == right && left_left->next == right_right);

    return 0;
}
