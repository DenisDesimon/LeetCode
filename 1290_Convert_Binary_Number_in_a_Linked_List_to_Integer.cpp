//#1290 Convert Binary Number in a Linked List to Integer - https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
#include <iostream>
#include <cassert>
using namespace std;


 //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while(head != NULL)
        {
            result <<= 1;
            result |= head->val;
            head = head->next;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    ListNode* given_node = new ListNode(1);
    given_node->next = new ListNode(0);
    given_node->next->next = new ListNode(1);
    int expected_answer = 5;
    assert(solution.getDecimalValue(given_node) == expected_answer);

    given_node = new ListNode(1);
    given_node->next = new ListNode(1);
    given_node->next->next = new ListNode(1);
    expected_answer = 7;
    assert(solution.getDecimalValue(given_node) == expected_answer);

    return 0;
}
