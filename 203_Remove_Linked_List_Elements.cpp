//#203 Remove Linked List Elements - https://leetcode.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* result = new ListNode(0);
        result->next = head;
        ListNode* cur = result->next;
        ListNode* prev = result;
        while(cur != NULL)
        {
            if(cur->val == val)
                prev->next = cur->next;
            else
                prev = cur;
            cur = cur->next;
        }
        return result->next;
    }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(1);
    given_list = new ListNode(2);
    given_list = new ListNode(6);
    given_list = new ListNode(3);
    given_list = new ListNode(4);
    given_list = new ListNode(5);
    given_list = new ListNode(6);

    ListNode* expected_answer = new ListNode(1);
    expected_answer = new ListNode(2);
    expected_answer = new ListNode(3);
    expected_answer = new ListNode(4);
    expected_answer = new ListNode(5);

    int given_val = 6;
    assert(*solution.removeElements(given_list, given_val) == *expected_answer);

    return 0;
}
