//#2 Add Two Numbers - https://leetcode.com/problems/add-two-numbers/
#include <iostream>
#include <cassert>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        int over = 0;
        while(l1 != NULL || l2 != NULL || over != 0)
        {
            int num = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + over;
            over = num / 10;
            num %= 10;
            head->next = new ListNode(num);
            head = head->next;
            l1 = (l1 == NULL ? l1 : l1->next);
            l2 = (l2 == NULL ? l2 : l2->next);
        }
        return result->next;
    }
};

int main()
{
    Solution solution;
    ListNode* given_l1 = new ListNode(2);
    given_l1->next = new ListNode(4);
    given_l1->next->next = new ListNode(3);

    ListNode* given_l2 = new ListNode(5);
    given_l2->next = new ListNode(6);
    given_l2->next->next = new ListNode(4);

    ListNode* expected_answer = new ListNode(7);
    expected_answer->next = new ListNode(0);
    expected_answer->next->next = new ListNode(8);

    ListNode* result = solution.addTwoNumbers(given_l1, given_l2);
    assert(result->val == expected_answer->val && result->next->val == expected_answer->next->val &&
           result->next->next->val == expected_answer->next->next->val);

    return 0;
}
