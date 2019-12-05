//#476 Number Complement - https://leetcode.com/problems/number-complement/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
    long long next_power_of_two(long long n){
        n--;
        n |= n >> 1;
        n |= n >> 2;
        n |= n >> 4;
        n |= n >> 8;
        n |= n >> 16;
        n++;
        return n;
    }
public:
    int findComplement(int num) {
        long long ones = next_power_of_two((long long)num + 1) - 1;
        return num ^ ones;
    }
};

int main()
{
    Solution solution;
    int given_n = 5;
    int expected_answer = 2;
    assert(solution.findComplement(given_n) == expected_answer);

    given_n = 1;
    expected_answer = 0;
    assert(solution.findComplement(given_n) == expected_answer);

    return 0;
}
