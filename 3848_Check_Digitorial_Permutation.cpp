//#3848 Check Digitorial Permutation - https://leetcode.com/problems/check-digitorial-permutation/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fact(10, 1);
        for(int i = 1; i < 10; i++)
            fact[i] = i * fact[i - 1];
        long long sum = 0;
        string nStr = to_string(n);
        sort(nStr.begin(), nStr.end());
        while(n)
        {
            sum += fact[n % 10];
            n /= 10;
        }
        string sumStr = to_string(sum);
        sort(sumStr.begin(), sumStr.end());
        return nStr == sumStr;
    }
};

int main()
{
    Solution solution;
    int givenN = 10;
    bool expectedAnswer = false;
    assert(solution.isDigitorialPermutation(givenN) == expectedAnswer);

    givenN = 451;
    expectedAnswer = true;
    assert(solution.isDigitorialPermutation(givenN) == expectedAnswer);

    return 0;
}
