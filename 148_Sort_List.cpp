//#148 Sort List - https://leetcode.com/problems/sort-list/
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
    ListNode* merge(ListNode* left, ListNode* right)
    {
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        if(left->val < right->val)
        {
            left->next = merge(left->next, right);
            return left;
        }
        else
        {
            right->next = merge(left, right->next);
            return right;
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = head;
        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        auto left = sortList(head);
        auto right = sortList(slow);
        return merge(left, right);
    }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(4);
    given_list->next = new ListNode(2);
    given_list->next->next = new ListNode(3);
    given_list->next->next->next = new ListNode(1);

    ListNode* expected_answer = new ListNode(1);
    expected_answer->next  = new ListNode(2);
    expected_answer->next ->next  = new ListNode(3);
    expected_answer->next ->next ->next  = new ListNode(4);

    assert(*solution.sortList(given_list) == *expected_answer);

    return 0;
}
