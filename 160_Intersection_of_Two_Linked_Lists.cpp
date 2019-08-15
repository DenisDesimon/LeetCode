//#160 Intersection of Two Linked Lists - https://leetcode.com/problems/intersection-of-two-linked-lists/
#include <iostream>
#include <cassert>
#include <unordered_set>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        while(headA != NULL || headB != NULL)
        {
            if(visited.count(headA))
                return headA;
            if(headA != NULL)
            {
                visited.insert(headA);
                headA = headA->next;
            }
            if(visited.count(headB))
                return headB;
            if(headB != NULL)
            {
                visited.insert(headB);
                headB = headB->next;
            }
        }
        return NULL;
    }
};

int main()
{
    Solution solution;
    ListNode* given_listA = new ListNode(1);
    given_listA->next = new ListNode(2);
    given_listA->next->next = new ListNode(3);
    given_listA->next->next->next = new ListNode(4);
    given_listA->next->next->next->next = new ListNode(5);

    ListNode* given_listB = new ListNode(1);
    given_listB = new ListNode(2);
    given_listB = new ListNode(3);
    given_listB = given_listA->next->next->next;

    ListNode* expected_answer = given_listA->next->next->next;
    assert(solution.getIntersectionNode(given_listA, given_listB) == expected_answer);

    return 0;
}
