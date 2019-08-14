//#142 Linked List Cycle II - https://leetcode.com/problems/linked-list-cycle-ii/
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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while(head != NULL)
        {
            if(visited.count(head))
                return head;
            visited.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(3);
    given_list->next = new ListNode(2);
    given_list->next->next = new ListNode(0);
    given_list->next->next->next = new ListNode(-4);
    given_list->next->next->next->next = given_list->next;

    ListNode* expected_answer = given_list->next;
    assert(solution.detectCycle(given_list) == expected_answer);

    given_list = new ListNode(1);
    given_list->next = new ListNode(2);
    given_list->next->next = given_list;

    expected_answer = given_list;
    assert(solution.detectCycle(given_list) == expected_answer);

    return 0;
}
