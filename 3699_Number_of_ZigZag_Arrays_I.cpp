//#3699 Number of ZigZag Arrays I - https://leetcode.com/problems/number-of-zigzag-arrays-i/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int MOD = 1e9 + 7;
        vector<int> dpDown(m);
        vector<int> dpUp(m);
        vector<int> sumDown(m + 1);
        vector<int> sumUp(m + 1);
        for(int i = 0; i < m; i++)
        {
            dpDown[i] = dpUp[i] = 1;
        }
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                sumDown[j + 1] = (sumDown[j] + dpDown[j]) % MOD;
                sumUp[j + 1] = (sumUp[j] + dpUp[j]) % MOD;
            }

            for(int j = 0; j < m; j++)
            {
                dpDown[j] = (sumUp[m] - sumUp[j + 1] + MOD) % MOD;
                dpUp[j] = sumDown[j];
            }

        }
        int result = 0;
        for(int i = 0; i < m; i++)
        {
            result = (result + dpDown[i]) % MOD;
            result = (result + dpUp[i]) % MOD;
        }
        return result;
    }
};


int main()
{
    Solution solution;
    int givenN = 3;
    int givenL = 4;
    int givenR = 5;
    int expectedAnswer = 2;
    assert(solution.zigZagArrays(givenN, givenL, givenR) == expectedAnswer);

    givenN = 3;
    givenL = 1;
    givenR = 3;
    expectedAnswer = 10;
    assert(solution.zigZagArrays(givenN, givenL, givenR) == expectedAnswer);

    return 0;
}
