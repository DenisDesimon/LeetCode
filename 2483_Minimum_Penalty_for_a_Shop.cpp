//#2483 Minimum Penalty for a Shop - https://leetcode.com/problems/minimum-penalty-for-a-shop/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int result = 0;
        int n = customers.size();
        int curPenalty = 0;
        for(int i = n - 1; i >= 0; i--)
            curPenalty += customers[i] == 'Y' ? 1 : 0;
        int minPenalty = INT_MAX;
        for(int i = 0; i <= n; i++)
        {
            if(i > 0)
                curPenalty += customers[i - 1] == 'N' ? 1 : -1;
            if(curPenalty < minPenalty)
            {
                minPenalty = curPenalty;
                result = i;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenCustomers  = "YYNY";
    int expectedAnswer = 2;
    assert(solution.bestClosingTime(givenCustomers) == expectedAnswer);

    givenCustomers = "NNNNN";
    expectedAnswer = 0;
    assert(solution.bestClosingTime(givenCustomers) == expectedAnswer);

    return 0;
}
