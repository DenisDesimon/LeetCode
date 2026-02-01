//#3827 Count Monobit Integers - https://leetcode.com/problems/count-monobit-integers/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int countMonobit(int n) {
        int result = 0;
        n++;
        while(n)
        {
            n >>= 1;
            result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 1;
    int expectedAnswer = 2;
    assert(solution.countMonobit(givenN) == expectedAnswer);

    givenN = 4;
    expectedAnswer = 3;
    assert(solution.countMonobit(givenN) == expectedAnswer);


    return 0;
}
