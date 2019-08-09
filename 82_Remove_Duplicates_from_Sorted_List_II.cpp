//#82 Remove Duplicates from Sorted List II - https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* result = new ListNode(0);
        ListNode* pre = result;
        result->next = head;
        while(head != NULL)
        {
            if(head->next != NULL && head->next->val == head->val)
            {
                while(head->next != NULL && head->next->val == head->val)
                    head = head->next;
                head = head->next;
                pre->next = head;
            }
            else
            {
                pre = head;
                head = head->next;
            }
        }

        return result->next;
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
    expected_answer->next->next = new ListNode(2);
    expected_answer->next->next->next = new ListNode(5);

    assert(*solution.deleteDuplicates(given_list) == *expected_answer);

    return 0;
}
