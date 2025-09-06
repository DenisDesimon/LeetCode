//#3495 Minimum Operations to Make Array Elements  - https://leetcode.com/problems/minimum-operations-to-make-array-elements-zero/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
private:
    long long countOperationsRange(int right){
        int numShifts = 1;
        int curPower = 1;
        long long result = 0;
        while(right >= curPower)
        {
            result += (long long)(numShifts + 1) / 2 * (min(right, curPower * 2 - 1) - curPower + 1);
            curPower <<= 1;
            numShifts++;
        }
        return result;

    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        for(auto &query : queries)
        {
            result += (countOperationsRange(query[1]) - countOperationsRange(query[0] - 1) + 1) / 2;
        }
        return result;
    }
};



int main()
{
    Solution solution;
    vector<vector<int>> givenQueries = {{1, 8}};
    long long expectedAnswer = 7;
    assert(solution.minOperations(givenQueries) == expectedAnswer);

    givenQueries = {{1, 2}, {2, 4}};
    expectedAnswer = 3;
    assert(solution.minOperations(givenQueries) == expectedAnswer);

    return 0;
}
