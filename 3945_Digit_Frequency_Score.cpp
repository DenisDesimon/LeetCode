//#3945 Digit Frequency Score - https://leetcode.com/problems/digit-frequency-score/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int digitFrequencyScore(int n) {
        int count[10] = {0};
        while(n)
        {
            count[n % 10]++;
            n /= 10;
        }
        int result = 0;
        for(int i = 0; i < 10; i++)
            result += i * count[i];
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 122;
    int expectedAnswer = 5;
    assert(solution.digitFrequencyScore(givenN) == expectedAnswer);

    givenN = 101;
    expectedAnswer = 2;
    assert(solution.digitFrequencyScore(givenN) == expectedAnswer);

    return 0;
}
