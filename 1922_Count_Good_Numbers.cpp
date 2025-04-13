//#1922 Count Good Numbers - https://leetcode.com/problems/count-good-numbers/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
private:
    int mod = 1000000007;
    int fastExponent(long long base, long long exponent){
        int result = 1;
        while(exponent > 0)
        {
            if(exponent & 1)
                result = result * base % mod;
            base = base * base % mod;
            exponent >>= 1;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        return (long long)fastExponent(4, n / 2) * fastExponent(5, (n + 1) / 2) % mod;
    }
};

int main()
{
    Solution solution;
    int given_n = 4;
    int expected_answer = 400;
    assert(solution.countGoodNumbers(given_n) == expected_answer);

    given_n = 50;
    expected_answer = 564908303;
    assert(solution.countGoodNumbers(given_n) == expected_answer);

    return 0;
}
