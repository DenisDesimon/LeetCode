//#876 Middle of the Linked List - https://leetcode.com/problems/middle-of-the-linked-list/
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
                return val == b.val && (*next) == *b.next;
            }
  };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* Fast = head;
        ListNode* Slow = head;
        while(Fast != NULL && Fast->next != NULL)
        {
            Fast = Fast->next->next;
            Slow = Slow->next;
        }
        return Slow;
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

    ListNode* expected_answer = new ListNode(3);
    expected_answer->next = new ListNode(4);
    expected_answer->next->next = new ListNode(5);

    assert(*solution.middleNode(given_list) == *expected_answer);

    return 0;
}
