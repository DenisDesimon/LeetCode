//#19 Remove Nth Node From End of List - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#include <iostream>
#include <cassert>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
      bool operator ==(ListNode b){
          bool next_node = true;
          if(b.next == NULL && this->next == NULL)
              next_node = true;
          else if(b.next == NULL || this->next == NULL)
              next_node = false;
          return val == b.val && next_node && *next == *b.next;
      }
  };

class Solution {
    int find_end(ListNode* head, int &n){
        if(head == NULL)
            return 0;
        int pos = find_end(head->next, n) + 1;
        if(pos == n + 1)
            head->next = head->next->next;
        return pos;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(find_end(head, n) == n)
            return head->next;
        return head;
    }
};

int main()
{
    Solution solution;
    ListNode* given_Node = new ListNode(1);
    given_Node->next = new ListNode(2);
    given_Node->next ->next = new ListNode(3);
    given_Node->next ->next ->next  = new ListNode(4);
    given_Node->next ->next ->next ->next = new ListNode(5);

    int given_n = 2;

    ListNode* expected_answer = new ListNode(1);
    expected_answer->next = new ListNode(2);
    expected_answer->next->next = new ListNode(3);
    expected_answer->next->next->next = new ListNode(5);
    assert(*solution.removeNthFromEnd(given_Node, given_n) == *expected_answer);
    return 0;
}
