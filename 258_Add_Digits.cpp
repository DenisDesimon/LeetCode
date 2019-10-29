//#258 Add Digits - https://leetcode.com/problems/add-digits/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return (num - 1) % 9 + 1;
    }
};

int main()
{
    Solution solution;
    int given_num = 38;
    int expected_answer = 2;
    assert(solution.addDigits(given_num) == expected_answer);

    given_num = 9;
    expected_answer = 9;
    assert(solution.addDigits(given_num) == expected_answer);

    return 0;
}
