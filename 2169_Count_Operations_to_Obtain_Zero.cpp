//#2169 Count Operations to Obtain Zero - https://leetcode.com/problems/count-operations-to-obtain-zero/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0;
        while(num1 && num2)
        {
            count += num1 / num2;
            num1 %= num2;
            swap(num1, num2);
        }
        return count;
    }
};

int main()
{
    Solution solution;
    int givenNum1 = 2;
    int givenNum2 = 3;
    int expectedAnswer = 3;
    assert(solution.countOperations(givenNum1, givenNum2) == expectedAnswer);

    givenNum1 = 10;
    givenNum2 = 10;
    expectedAnswer = 1;
    assert(solution.countOperations(givenNum1, givenNum2) == expectedAnswer);

    return 0;
}
