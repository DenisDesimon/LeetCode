//#1281 Subtract the Product and Sum of Digits of an Integer - https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        int digit;
        while(n)
        {
            digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }
        return product - sum;
    }
};

int main()
{
    Solution solution;
    int given_n = 234;
    int expected_answer = 15;
    assert(solution.subtractProductAndSum(given_n) == expected_answer);

    given_n = 4421;
    expected_answer = 21;
    assert(solution.subtractProductAndSum(given_n) == expected_answer);

    return 0;
}
