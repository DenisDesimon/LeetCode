//#3217 Delete Nodes From Linked List Present in Array - https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    bool operator ==(ListNode right){
        if(right.next == NULL && next == NULL)
             return val == right.val;
        else if(right.next == NULL || next == NULL)
             return false;
        return val == right.val && *next == *right.next;
   }
};


class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numsToRemove(nums.begin(), nums.end());
        ListNode dummy(0);
        dummy.next = head;
        ListNode* cur= &dummy;
        while(cur && cur->next)
        {
            if(numsToRemove.count(cur->next->val))
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return dummy.next;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 3};
    ListNode *givenHead = new ListNode(1);
    givenHead->next = new ListNode(2);
    givenHead->next->next = new ListNode(3);
    givenHead->next->next->next = new ListNode(4);
    givenHead->next->next->next->next = new ListNode(5);
    ListNode *expectedAnswer = new ListNode(4);
    expectedAnswer->next = new ListNode(5);
    assert(*solution.modifiedList(givenNums, givenHead) == *expectedAnswer);



    return 0;
}
