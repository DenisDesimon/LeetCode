//#754 Reach a Number - https://leetcode.com/problems/reach-a-number/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = 0;
        while(target > 0)
            target -= ++n;
        return target % 2 == 0 ? n : n + 1 + n % 2;
    }
};

int main()
{
    Solution solution;
    int given_target = 3;
    int expected_answer = 2;
    assert(solution.reachNumber(given_target) == expected_answer);

    given_target = 9;
    expected_answer = 5;
    assert(solution.reachNumber(given_target) == expected_answer);

    return 0;
}
