//#2095 Delete the Middle Node of a Linked List - https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
#include <iostream>
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next)
            return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        return head;
    }
};

int main()
{
    Solution solution;
    ListNode *givenHead = new ListNode(1);
    givenHead->next = new ListNode(2);
    givenHead->next->next = new ListNode(3);
    givenHead->next->next->next = new ListNode(4);
    ListNode *expectedAnswer = new ListNode(1);
    expectedAnswer->next = new ListNode(2);
    expectedAnswer->next->next = new ListNode(4);
    assert(*solution.deleteMiddle(givenHead) == *expectedAnswer);

    givenHead = new ListNode(2);
    givenHead->next = new ListNode(1);
    expectedAnswer = new ListNode(2);

    assert(*solution.deleteMiddle(givenHead) == *expectedAnswer);

    return 0;
}
