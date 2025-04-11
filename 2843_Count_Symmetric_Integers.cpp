//#2843 Count Symmetric Integers - https://leetcode.com/problems/count-symmetric-integers/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int result = 0;
        for(int num = low; num <= high; num++)
        {
            if(num >= 11 && num <= 99 && num % 11 == 0)
                result++;
            else if(num >= 1001 && num <= 9999)
            {
                int left = (num / 100) % 10 + num / 1000;
                int right = num % 10 + (num % 100) / 10;
                result += left == right;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_low = 1;
    int given_high = 100;
    int expectedAnswer = 9;
    assert(solution.countSymmetricIntegers(given_low, given_high) == expectedAnswer);


    given_low = 1200;
    given_high = 1230;
    expectedAnswer = 4;
    assert(solution.countSymmetricIntegers(given_low, given_high) == expectedAnswer);

    return 0;
}
