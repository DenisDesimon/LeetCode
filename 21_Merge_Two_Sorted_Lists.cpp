//#21 Merge Two Sorted Lists - https://leetcode.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 == NULL)
            {
                head->next = new ListNode(l2->val);
                l2 = l2->next;
                head = head->next;
            }
            else if(l2 == NULL)
            {
                head->next = new ListNode(l1->val);
                l1 = l1->next;
                head = head->next;
            }
            else if(l1->val < l2->val)
            {
                head->next = new ListNode(l1->val);
                l1 = l1->next;
                head = head->next;
            }
            else
            {
                head->next = new ListNode(l2->val);
                l2 = l2->next;
                head = head->next;
            }
        }
        return result->next;
    }
};

int main()
{
    Solution solution;
    ListNode* given_l1 = new ListNode(1);
    given_l1->next = new ListNode(2);
    given_l1->next ->next = new ListNode(4);

    ListNode* given_l2 = new ListNode(1);
    given_l2->next = new ListNode(3);
    given_l2->next ->next = new ListNode(4);



    ListNode* expected_answer = new ListNode(1);
    expected_answer->next = new ListNode(1);
    expected_answer->next->next = new ListNode(2);
    expected_answer->next->next->next = new ListNode(3);
    expected_answer->next->next->next->next = new ListNode(4);
    expected_answer->next->next->next->next->next = new ListNode(4);

    assert(*solution.mergeTwoLists(given_l1, given_l2) == *expected_answer);

    return 0;
}
