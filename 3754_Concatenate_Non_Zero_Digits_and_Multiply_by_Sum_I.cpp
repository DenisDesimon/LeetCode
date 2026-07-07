//#3754 Concatenate Non-Zero Digits and Multiply by Sum I - https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/
#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        string reversed = "";
        while(n)
        {
            if(n % 10)
            {
                sum += n % 10;
                reversed += '0' + n % 10;
            }
            n /= 10;
        }
        reverse(reversed.begin(), reversed.end());
        if(!reversed.empty())
            x = stoi(reversed);
        return x * sum;
    }
};

int main()
{
    Solution solution;
    int givenN = 10203004;
    long long expectedAnswer = 12340;
    assert(solution.sumAndMultiply(givenN) == expectedAnswer);

    givenN = 1000;
    expectedAnswer = 1;
    assert(solution.sumAndMultiply(givenN) == expectedAnswer);

    return 0;
}
