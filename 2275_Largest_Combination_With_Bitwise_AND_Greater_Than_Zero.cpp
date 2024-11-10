//#2275 Largest Combination With Bitwise AND Greater Than Zero - https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int result = 0;
        for(int i = 0; i < 24; i++)
        {
            int count = 0;
            for(auto candidate : candidates)
            {
                if(1 & (candidate >>i))
                    count++;
                result = max(result, count);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_candidates = {16, 17, 71, 62, 12, 24, 14};
    int expected_answer = 4;
    assert(solution.largestCombination(given_candidates) == expected_answer);

    given_candidates = {8, 8};
    expected_answer = 2;
    assert(solution.largestCombination(given_candidates) == expected_answer);

    return 0;
}
