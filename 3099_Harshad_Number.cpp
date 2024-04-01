//#3099 Harshad Number - https://leetcode.com/problems/harshad-number/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int temp = x;
        while(temp)
        {
            sum += temp % 10;
            temp /= 10;
        }
        return x % sum ? -1 : sum;
    }
};

int main()
{
    Solution solution;
    int given_x = 18;
    int expected_answer = 9;
    assert(solution.sumOfTheDigitsOfHarshadNumber(given_x) == expected_answer);

    given_x = 23;
    expected_answer = -1;
    assert(solution.sumOfTheDigitsOfHarshadNumber(given_x) == expected_answer);

    return 0;
}
