//#141 Linked List Cycle - https://leetcode.com/problems/linked-list-cycle/
#include <iostream>
#include <unordered_set>
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
    bool hasCycle_2pointers(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL)
        {
            if(fast == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
    bool hasCycle(ListNode *head) {
            unordered_set<ListNode*> visited;
            while(head != NULL)
            {
                if(visited.count(head))
                    return true;
                visited.insert(head);
                head = head->next;
            }
            return false;
        }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(3);
    given_list->next = new ListNode(2);
    given_list->next->next = new ListNode(0);
    given_list->next->next->next = new ListNode(-4);
    given_list->next->next->next->next = given_list;

    bool expected_answer = true;
    assert(solution.hasCycle(given_list) == expected_answer);
    assert(solution.hasCycle_2pointers(given_list) == expected_answer);

    given_list = new ListNode(1);
    given_list->next = new ListNode(2);
    given_list->next->next = given_list;

    expected_answer = true;
    assert(solution.hasCycle(given_list) == expected_answer);
    assert(solution.hasCycle_2pointers(given_list) == expected_answer);

    return 0;
}
