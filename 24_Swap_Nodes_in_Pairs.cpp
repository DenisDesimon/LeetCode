//#24 Swap Nodes in Pairs - https://leetcode.com/problems/swap-nodes-in-pairs/
#include <iostream>
#include <cassert>
using namespace std;


  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        auto left_swap = head->next;
        auto temp = head->next->next;
        head->next->next = head;
        head->next = swapPairs(temp);
        return left_swap;

    }
};

int main()
{
    Solution solution;
    ListNode* given_list1 = new ListNode(1);
    ListNode* given_list2 = new ListNode(2);
    given_list1->next = given_list2;
    ListNode* given_list3 = new ListNode(3);
    given_list2->next = given_list3;
    ListNode* given_list4 = new ListNode(4);
    given_list3->next = given_list4;
    solution.swapPairs(given_list1);
    assert(given_list2->next == given_list1);
    assert(given_list1->next == given_list4);
    assert(given_list4->next == given_list3);

    return 0;
}
