//#382 Linked List Random Node - https://leetcode.com/problems/linked-list-random-node/
#include <iostream>
#include <cassert>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
    int size_list = 0;
    ListNode* Node;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        Node = head;
        while(head != NULL && head->next != NULL)
        {
            size_list += 2;
            head = head->next->next;
        }
        if(head != NULL)
            size_list++;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int rand_acces = rand() % size_list;
        ListNode* head = Node;
        while(rand_acces)
        {
            head = head->next;
            rand_acces--;
        }
        return head->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{
    ListNode* given_List = new ListNode(1);
    given_List->next = new ListNode(2);
    given_List->next->next = new ListNode(3);
    Solution solution(given_List);
    int result = solution.getRandom();
    assert(result == 1 || result == 1 || result == 3);

    return 0;
}
