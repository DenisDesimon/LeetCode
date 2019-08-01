//#61 Rotate List - https://leetcode.com/problems/rotate-list/
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
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;
        int size = 1;
        ListNode* tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
            size++;
        }
        k %= size;
        if(size == 1 || k == 0)
            return head;
        ListNode* tail_left = head;
        k = size - k;
        while(k-- > 1)
            tail_left = tail_left->next;
        ListNode* result = tail_left->next;
        tail_left->next = NULL;
        tail->next = head;
        return result;
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

    ListNode* expected_answer = new ListNode(4);
    expected_answer->next = new ListNode(5);
    expected_answer->next->next = new ListNode(1);
    expected_answer->next->next->next = new ListNode(2);
    expected_answer->next->next->next->next = new ListNode(3);

    int given_k = 2;
    assert(*solution.rotateRight(given_list, given_k) == *expected_answer);

    return 0;
}
