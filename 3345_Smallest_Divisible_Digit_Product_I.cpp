//#3345 Smallest Divisible Digit Product I - https://leetcode.com/problems/smallest-divisible-digit-product-i/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = 0; i < 10; i++)
        {
            int num = n + i;
            int product = 1;
            while(num)
            {
                product *= num % 10;
                num /= 10;
            }
            if(product % t == 0)
                return n + i;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    int givenN = 10;
    int givenK = 2;
    int expectedAnswer = 10;
    assert(solution.smallestNumber(givenN, givenK) == expectedAnswer);

    givenN = 15;
    givenK = 3;
    expectedAnswer = 16;
    assert(solution.smallestNumber(givenN, givenK) == expectedAnswer);

    return 0;
}
