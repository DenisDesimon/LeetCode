//#206 Reverse Linked List - https://leetcode.com/problems/reverse-linked-list/
#include <iostream>
#include <cassert>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
      bool operator ==(ListNode b){
                      if(b.next == NULL && next == NULL)
                          return val == b.val;
                      else if(b.next == NULL || next == NULL)
                          return false;
                      return val == b.val && *next == *b.next;
                  }
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp;
        while(head != NULL)
        {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(1);
    given_list->next = new ListNode(2);
    given_list->next->next = new ListNode(3);
    given_list->next->next->next = new ListNode(4);
    given_list->next->next->next->next = new ListNode(5);

    ListNode* expected_answer = new ListNode(5);
    expected_answer->next = new ListNode(4);
    expected_answer->next->next = new ListNode(3);
    expected_answer->next->next->next = new ListNode(2);
    expected_answer->next->next->next->next = new ListNode(1);

    assert(*solution.reverseList(given_list) == *expected_answer);

    return 0;
}
