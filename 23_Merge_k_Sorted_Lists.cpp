//#23 Merge k Sorted Lists - https://leetcode.com/problems/merge-k-sorted-lists/
#include <iostream>
#include <vector>
#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = new ListNode(0);
        ListNode* head = result;
        priority_queue<int> nodes;
        bool is_end = false;
        while(!is_end)
        {
            int size_nodes = nodes.size();
            for(auto &node : lists)
            {
                if(node != NULL)
                {
                    nodes.push(-node->val);
                    node = node->next;
                }
            }
            if(size_nodes == (int)nodes.size())
                is_end = true;
            else
            {
                head->next = new ListNode(-nodes.top());
                nodes.pop();
                head = head->next;
            }
        }
        while(!nodes.empty())
        {
            head->next = new ListNode(-nodes.top());
            nodes.pop();
            head = head->next;
        }
        return result->next;
    }
};

int main()
{
    Solution solution;
    ListNode* given_l1 = new ListNode(1);
    given_l1->next = new ListNode(2);
    given_l1->next ->next = new ListNode(4);

    ListNode* given_l2 = new ListNode(1);
    given_l2->next = new ListNode(3);
    given_l2->next ->next = new ListNode(4);

    vector<ListNode*> given_list = {given_l1, given_l2};


    ListNode* expected_answer = new ListNode(1);
    expected_answer->next = new ListNode(1);
    expected_answer->next->next = new ListNode(2);
    expected_answer->next->next->next = new ListNode(3);
    expected_answer->next->next->next->next = new ListNode(4);
    expected_answer->next->next->next->next->next = new ListNode(4);

    solution.mergeKLists(given_list);

    return 0;
}
