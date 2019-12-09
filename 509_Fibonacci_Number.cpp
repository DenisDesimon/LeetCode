//#509 Fibonacci Number - https://leetcode.com/problems/fibonacci-number/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int fib(int N) {
        if(N == 0)
            return 0;
        int result = 1;
        int prev = 0;
        int swap;
        N--;
        while(N--)
        {
            swap = result;
            result = prev + result;
            prev = swap;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_N = 3;
    int expected_anaswer = 2;
    assert(solution.fib(given_N) == expected_anaswer);

    given_N = 0;
    expected_anaswer = 0;
    assert(solution.fib(given_N) == expected_anaswer);

    return 0;
}
