//#869 Reordered Power of 2 - https://leetcode.com/problems/reordered-power-of-2/
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
    string sortedNum(int n){
        string numStr = to_string(n);
        sort(numStr.begin(), numStr.end());
        return numStr;
    }
public:
    bool reorderedPowerOf2(int n) {
        string numStr = sortedNum(n);
        for(int i = 0; i < 32; i++)
        {
            if(numStr == sortedNum(1 << i))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    int givenN = 1;
    bool expectedAnswer = true;
    assert(solution.reorderedPowerOf2(givenN) == expectedAnswer);

    givenN = 10;
    expectedAnswer = false;
    assert(solution.reorderedPowerOf2(givenN) == expectedAnswer);

    return 0;
}
