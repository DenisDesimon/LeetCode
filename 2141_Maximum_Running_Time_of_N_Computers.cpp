//#2141 Maximum Running Time of N Computers - https://leetcode.com/problems/maximum-running-time-of-n-computers/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long chargeSum = 0;
        for(auto &battery : batteries)
            chargeSum += battery;
        long long left = 1, right = chargeSum / n;
        while(left < right)
        {
            long long target = right - (right - left) / 2;
            long long chargeAvailable = 0;
            for(auto &battery : batteries)
                chargeAvailable += min(target, (long long)battery);
            if(chargeAvailable >= target * n)
                left = target;
            else
                right = target - 1;

        }
        return left;
    }
};

int main()
{
    Solution solution;
    vector<int> givenBatteries = {3, 3, 3};
    int givenN = 2;
    long long expectedAnswer = 4;
    assert(solution.maxRunTime(givenN, givenBatteries) == expectedAnswer);

    givenBatteries = {1, 1, 1, 1};
    givenN = 2;
    expectedAnswer = 2;
    assert(solution.maxRunTime(givenN, givenBatteries) == expectedAnswer);

    return 0;
}
