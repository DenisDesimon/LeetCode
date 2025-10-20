//#2011 Final Value of Variable After Performing Operations - https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int result = 0;
        for(auto &operation : operations)
        {
            if(operation[1] == '+')
                result++;
            else
                result--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> givenOperations = {"--X", "X++", "X++"};
    int expectedAnswer = 1;
    assert(solution.finalValueAfterOperations(givenOperations) == expectedAnswer);

    givenOperations = {"X++", "++X", "--X", "X--"};
    expectedAnswer = 0;
    assert(solution.finalValueAfterOperations(givenOperations) == expectedAnswer);

    return 0;
}
