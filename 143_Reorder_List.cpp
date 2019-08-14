//#143 Reorder List - https://leetcode.com/problems/reorder-list/
#include <iostream>
#include <stack>
#include <cassert>
using namespace std;


 // Definition for singly-linked list.
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
    void reorderList(ListNode* head) {
        ListNode* node = head;
        stack<ListNode*> nodes;
        while(node != NULL)
        {
            nodes.push(node);
            node = node->next;
        }
        while(!nodes.empty())
        {
            auto cur_node = nodes.top();
            nodes.pop();
            if(head == cur_node)
            {
                head->next = NULL;
                break;
            }
            else if(head->next == cur_node)
            {
                cur_node->next = NULL;
                break;
            }
            auto temp = head->next;
            head->next = cur_node;
            cur_node->next = temp;
            head = temp;
        }
    }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(1);
    given_list->next = new ListNode(2);
    given_list->next->next = new ListNode(3);
    given_list->next->next->next = new ListNode(4);

    ListNode* expected_answer = new ListNode(1);
    expected_answer->next = new ListNode(4);
    expected_answer->next->next = new ListNode(2);
    expected_answer->next->next->next = new ListNode(3);

    solution.reorderList(given_list);
    assert(*given_list == *expected_answer);

    return 0;
}
