//#1304 Find N Unique Integers Sum up to Zero  - https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for(int i = 1; i <= n / 2; i++)
        {
            result.push_back(i);
            result.push_back(-i);
        }
        if(n % 2)
            result.push_back(0);
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 5;
    vector<int> expectedAnswer = {1, -1, 2, -2, 0};
    assert(solution.sumZero(givenN) == expectedAnswer);

    givenN = 3;
    expectedAnswer = {1, -1, 0};
    assert(solution.sumZero(givenN) == expectedAnswer);

    return 0;
}
