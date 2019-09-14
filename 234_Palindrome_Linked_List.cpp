//#234 Palindrome Linked List - https://leetcode.com/problems/palindrome-linked-list/
#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        stack<ListNode*> nodes;
        while(fast != NULL && fast->next != NULL)
        {
            nodes.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL)
            slow = slow->next;
        while(slow != NULL)
        {
            if(nodes.top()->val != slow->val)
                return false;
            slow = slow->next;
            nodes.pop();
        }
        return true;
    }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(1);
    given_list->next = new ListNode(2);
    given_list->next->next = new ListNode(2);
    given_list->next->next->next = new ListNode(1);
    bool expected_answer = true;
    assert(solution.isPalindrome(given_list) == expected_answer);

    given_list->next->next->next->next = new ListNode(3);
    expected_answer = false;
    assert(solution.isPalindrome(given_list) == expected_answer);

    return 0;
}
