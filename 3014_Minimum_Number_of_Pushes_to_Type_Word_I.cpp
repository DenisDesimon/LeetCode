//#3014 Minimum Number of Pushes to Type Word I - https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int result = 0;
        for(int i = 0; i < (int)word.size(); i++)
            result += i / 8 + 1;
        return result;
    }
};

int main()
{
    Solution solution;
    string givenWord = "abcde";
    int expectedAnswer = 5;
    assert(solution.minimumPushes(givenWord) == expectedAnswer);

    givenWord = "xycdefghij";
    expectedAnswer = 12;
    assert(solution.minimumPushes(givenWord) == expectedAnswer);

    return 0;
}
