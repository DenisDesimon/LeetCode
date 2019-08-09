//#83 Remove Duplicates from Sorted List - https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
                    return val == b.val;
                else if(b.next == NULL || this->next == NULL)
                    return false;
                return val == b.val && next_node && *next == *b.next;
            }
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* result = head;
        while(head != NULL)
        {
            if(head->next != NULL && head->next->val == head->val)
                head->next = head->next->next;
            else
                head = head->next;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(1);
    given_list->next = new ListNode(2);
    given_list->next->next = new ListNode(3);
    given_list->next->next->next= new ListNode(3);
    given_list->next->next->next->next = new ListNode(4);
    given_list->next->next->next->next->next = new ListNode(4);
    given_list->next->next->next->next->next->next = new ListNode(5);

    ListNode* expected_answer = new ListNode(1);
    expected_answer->next = new ListNode(2);
    expected_answer->next->next = new ListNode(3);
    expected_answer->next->next->next = new ListNode(4);
    expected_answer->next->next->next->next = new ListNode(5);

    assert(*solution.deleteDuplicates(given_list) == *expected_answer);

    return 0;
}
