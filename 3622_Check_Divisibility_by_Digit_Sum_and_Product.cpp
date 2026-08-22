//#3622 Check Divisibility by Digit Sum and Product - https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, product = 1;
        int num = n;
        while(num)
        {
            sum += num % 10;
            product *= num % 10;
            num /= 10;
        }
        return n % (sum + product) == 0;
    }
};

int main()
{
    Solution solution;
    int givenN = 99;
    bool expectedAnswer = true;
    assert(solution.checkDivisibility(givenN) == expectedAnswer);

    givenN = 23;
    expectedAnswer = false;
    assert(solution.checkDivisibility(givenN) == expectedAnswer);


    return 0;
}
