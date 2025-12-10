//#3577 Count the Number of Computer Unlocking Permutations - https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mod = 1e9 + 7;
        for(int i = 1; i < (int)complexity.size(); i++)
        {
            if(complexity[i] <= complexity.front())
                return 0;
        }
        long long result = 1;
        for(int i = 2; i < (int)complexity.size(); i++)
            result = result * i % mod;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenComplexity = {1, 2, 3, 4};
    int expectedAnswer = 6;
    assert(solution.countPermutations(givenComplexity) == expectedAnswer);

    givenComplexity = {3, 3, 3, 4, 4, 4};
    expectedAnswer = 0;
    assert(solution.countPermutations(givenComplexity) == expectedAnswer);

    return 0;
}
