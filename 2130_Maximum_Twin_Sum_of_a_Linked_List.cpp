//#2130 Maximum Twin Sum of a Linked List - https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            swap(slow->next, prev);
            swap(prev, slow);
        }
        int result = INT_MIN;
        while(slow)
        {
            result = max(result, slow->val + prev->val);
            slow = slow->next;
            prev = prev->next;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    ListNode *givenHead = new ListNode(5);
    givenHead->next = new ListNode(4);
    givenHead->next->next = new ListNode(2);
    givenHead->next->next->next = new ListNode(1);
    int expectedAnswer = 6;
    assert(solution.pairSum(givenHead) == expectedAnswer);

    givenHead = new ListNode(4);
    givenHead->next = new ListNode(2);
    givenHead->next->next = new ListNode(2);
    givenHead->next->next->next = new ListNode(3);
    expectedAnswer = 7;
    assert(solution.pairSum(givenHead) == expectedAnswer);

    return 0;
}
