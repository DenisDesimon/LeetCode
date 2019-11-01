//#319 Bulb Switcher - https://leetcode.com/problems/bulb-switcher/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int result = 0;
        int num = 1;
        while(num * num <= n)
        {
            result++;
            num++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 3;
    int expected_answer = 1;
    assert(solution.bulbSwitch(given_n) == expected_answer);

    given_n = 9;
    expected_answer = 3;
    assert(solution.bulbSwitch(given_n) == expected_answer);

    return 0;
}
