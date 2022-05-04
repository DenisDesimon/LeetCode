//#2235 Add Two Integers - https://leetcode.com/problems/add-two-integers/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int sum(int num1, int num2) {
        if(num2 == 0)
            return num1;
        return sum(num1 ^ num2, (unsigned)(num1 & num2) << 1);
    }
};

int main()
{
    Solution solution;
    int given_num1 = -5;
    int given_num2 = 9;
    int expected_answer = 4;
    assert(solution.sum(given_num1, given_num2) == expected_answer);

    given_num1 = -100;
    given_num2 = -100;
    expected_answer = -200;
    assert(solution.sum(given_num1, given_num2) == expected_answer);

    return 0;
}
