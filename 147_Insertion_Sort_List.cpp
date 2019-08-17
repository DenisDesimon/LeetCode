//#147 Insertion Sort List - https://leetcode.com/problems/insertion-sort-list/
#include <iostream>
#include <map>
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return head;
        multimap<int, ListNode*> sorted;
        while(head != NULL)
        {
            auto temp = head->next;
            auto iter = sorted.upper_bound(head->val);
            head->next = NULL;
            if(iter != sorted.begin())
            {
                iter--;
                (iter)->second->next = head;
                iter++;
            }
            if(iter != sorted.end())
                head->next = iter->second;
            sorted.insert(iter, {head->val, head});
            head = temp;
        }
        return sorted.begin()->second;
    }
};

int main()
{
    Solution solution;
    ListNode* given_node = new ListNode(4);
    given_node->next = new ListNode(2);
    given_node->next->next = new ListNode(3);
    given_node->next->next->next = new ListNode(1);

    ListNode* expected_answer = new ListNode(1);
    expected_answer->next = new ListNode(2);
    expected_answer->next->next = new ListNode(3);
    expected_answer->next->next->next = new ListNode(4);

    assert(*solution.insertionSortList(given_node) == *expected_answer);

    return 0;
}
