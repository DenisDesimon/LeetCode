//#3751 Total Waviness of Numbers in Range I - https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
#include <iostream>
#include <cassert>

using namespace std;


class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int result = 0;
        for(int i = num1; i <= num2; i++)
        {
            int num = i;
            int right = num % 10;
            num /= 10;
            int mid = num % 10;
            num /= 10;
            while(num)
            {
                int left = num % 10;
                if((left > mid && mid < right) || (left < mid && mid > right))
                    result++;
                right = mid;
                mid = left;
                num /= 10;
            }
        }
        return result;
    }
};


int main()
{
    Solution solution;
    int givenNum1 = 120;
    int givenNum2 = 130;
    int expectedAnswer = 3;
    assert(solution.totalWaviness(givenNum1, givenNum2) == expectedAnswer);

    givenNum1 = 198;
    givenNum2 = 202;
    expectedAnswer = 3;
    assert(solution.totalWaviness(givenNum1, givenNum2) == expectedAnswer);

    return 0;
}
