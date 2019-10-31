//#328 Odd Even Linked List - https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* head_even = even;
        while(even != NULL && even->next != NULL)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = head_even;
        return head;
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

    ListNode* expected_answer = new ListNode(1);
    expected_answer->next = new ListNode(3);
    expected_answer->next->next = new ListNode(5);
    expected_answer->next->next->next = new ListNode(2);
    expected_answer->next->next->next->next = new ListNode(4);


    assert(*solution.oddEvenList(given_list) == *expected_answer);

    return 0;
}
