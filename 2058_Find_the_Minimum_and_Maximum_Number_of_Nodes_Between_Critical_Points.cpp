//#2058 Find the Minimum and Maximum Number of Nodes Between Critical Points - https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int prev = head->val;
        head = head->next;
        vector<int> result(2, INT_MAX);
        int first = -1, last = -1, idx = 1;
        while(head && head->next)
        {
            if((head->val > prev && head->val > head->next->val) || (head->val < prev && head->val < head->next->val))
            {
                if(first == -1)
                    first = idx;
                else
                {
                    result = {min(result[0], idx - last), idx - first};
                }
                last = idx;
            }
            idx++;
            prev = head->val;
            head = head->next;
        }
        return result[1] == INT_MAX ? vector<int>(2, -1) : result;
    }
};

int main()
{
    Solution solution;
    ListNode* givenNode = new ListNode(5);
    givenNode->next = new ListNode(3);
    givenNode->next->next = new ListNode(1);
    givenNode->next->next->next = new ListNode(2);
    givenNode->next->next->next->next = new ListNode(5);
    givenNode->next->next->next->next->next = new ListNode(1);
    givenNode->next->next->next->next->next->next = new ListNode(2);
    vector<int> expectedAnswer = {1, 3};
    assert(solution.nodesBetweenCriticalPoints(givenNode) == expectedAnswer);

    givenNode = new ListNode(3);
    givenNode->next = new ListNode(1);
    expectedAnswer = {-1, -1};
    assert(solution.nodesBetweenCriticalPoints(givenNode) == expectedAnswer);

    return 0;
}
