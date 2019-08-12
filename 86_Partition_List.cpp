//#86 Partition List - https://leetcode.com/problems/partition-list/
#include <iostream>
#include <cassert>
using namespace std;

//Definition for singly-linked list.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left_head = new ListNode(0);
        ListNode* left = left_head;
        ListNode* right_head = new ListNode(0);
        ListNode* right = right_head;
        while(head != NULL)
        {
            if(head->val < x)
            {
                left->next = head;
                left = left->next;
            }
            else
            {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }
        right->next = NULL;
        left->next = right_head->next;
        return left_head->next;

    }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(1);
    given_list->next = new ListNode(4);
    given_list->next->next = new ListNode(3);
    given_list->next->next->next= new ListNode(2);
    given_list->next->next->next->next = new ListNode(5);
    given_list->next->next->next->next->next = new ListNode(2);

    ListNode* expected_answer = new ListNode(1);
    expected_answer->next = new ListNode(2);
    expected_answer->next->next = new ListNode(2);
    expected_answer->next->next->next = new ListNode(4);
    expected_answer->next->next->next->next = new ListNode(3);
    expected_answer->next->next->next->next->next = new ListNode(5);

    int given_x = 3;
    assert(*solution.partition(given_list, given_x) == *expected_answer);

    return 0;
}
