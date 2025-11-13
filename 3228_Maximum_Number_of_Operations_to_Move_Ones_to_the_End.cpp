//#3228 Maximum Number of Operations to Move Ones to the End - https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int result = 0, countOnes = 0;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] == '1')
                countOnes++;
            else if(i == (int)s.size() - 1 || s[i + 1] == '1')
                result += countOnes;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "1001101";
    int expectedAnswer = 4;
    assert(solution.maxOperations(givenS) == expectedAnswer);

    givenS = "11000100001";
    expectedAnswer = 5;
    assert(solution.maxOperations(givenS) == expectedAnswer);

    return 0;
}
