//#1137 N-th Tribonacci Number - https://leetcode.com/problems/n-th-tribonacci-number/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        else if(n == 1)
            return 1;
        else if(n == 2)
            return 1;
        int first = 0, second = 1, third = 1, result = 0;
        for(int i = 3; i <= n; i++)
        {
            result = first + second + third;
            first = second;
            second = third;
            third = result;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 4;
    int expected_answer = 4;
    assert(solution.tribonacci(given_n) == expected_answer);

    given_n = 25;
    expected_answer = 1389537;
    assert(solution.tribonacci(given_n) == expected_answer);

    return 0;
}
