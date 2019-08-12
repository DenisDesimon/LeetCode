//#92 Reverse Linked List II - https://leetcode.com/problems/reverse-linked-list-ii/
#include <iostream>
#include <cassert>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
      bool operator ==(ListNode b){
                if(b.next == NULL && this->next == NULL)
                    return val == b.val;
                else if(b.next == NULL || this->next == NULL)
                    return false;
                return val == b.val && *next == *b.next;
            }
  };

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(n == m)
            return head;
        ListNode* result = new ListNode(0);
        result->next = head;
        ListNode* head_m = result;
        for(int i = 0; i < m - 1; i++)
            head_m = head_m->next;
        ListNode* head_reverse = head_m->next;
        ListNode* prev = NULL;
        ListNode* temp = head_reverse;
        for(int i = 0; i < n - m + 1; i++)
        {
            head_m->next = head_reverse;
            ListNode* next_node = head_reverse->next;
            if(prev != NULL)
                head_reverse->next = prev;
            prev = head_reverse;
            head_reverse = next_node;
        }
        temp->next = head_reverse;
        return result->next;
    }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(1);
    given_list->next = new ListNode(2);
    given_list->next->next = new ListNode(3);
    given_list->next->next->next= new ListNode(4);
    given_list->next->next->next->next = new ListNode(5);


    ListNode* expected_answer = new ListNode(1);
    expected_answer->next = new ListNode(4);
    expected_answer->next->next = new ListNode(3);
    expected_answer->next->next->next = new ListNode(2);
    expected_answer->next->next->next->next = new ListNode(5);

    int given_n = 2, given_m = 4;
    assert(*solution.reverseBetween(given_list, given_n, given_m) == *expected_answer);

    return 0;
}
