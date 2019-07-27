//#25 Reverse Nodes in k-Group - https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1)
            return head;
        stack<ListNode*> nodes;
        ListNode* result = head;
        ListNode* right_next;
        ListNode* right;
        int m = k;
        while(k != 0)
        {
            if(head != NULL)
            {
                nodes.push(head);
                head = head->next;
            }
            else
                break;
            k--;
        }
        if(k == 0)
        {
            result = nodes.top();
            nodes.pop();
            auto temp = result;
            right_next = result->next;
            while(!nodes.empty())
            {
                temp->next = nodes.top();
                nodes.pop();
                temp = temp->next;
                right = temp;
            }
        }
        else
        {
            return result;
        }
        right->next = reverseKGroup(right_next, m);
        return result;
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

    ListNode* expected_answer = new ListNode(2);
    expected_answer->next = new ListNode(1);
    expected_answer->next->next = new ListNode(4);
    expected_answer->next->next->next = new ListNode(3);
    expected_answer->next->next->next->next = new ListNode(5);

    int given_n = 2;
    assert(*solution.reverseKGroup(given_list, given_n) == *expected_answer);

    return 0;
}
