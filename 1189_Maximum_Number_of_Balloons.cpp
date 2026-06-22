//#1189 Maximum Number of Balloons - https://leetcode.com/problems/maximum-number-of-balloons/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count[26] = {0};
        for(auto &letter : text)
            count[letter - 'a']++;
        int result = INT_MAX;
        result = min(result, count['b' - 'a']);
        result = min(result, count['a' - 'a']);
        result = min(result, count['l' - 'a'] / 2);
        result = min(result, count['o' - 'a'] / 2);
        result = min(result, count['n' - 'a']);
        return result;
    }
};

int main()
{
    Solution solution;
    string givenText = "nlaebolko";
    int expectedAnswer = 1;
    assert(solution.maxNumberOfBalloons(givenText) == expectedAnswer);

    givenText = "loonbalxballpoon";
    expectedAnswer = 2;
    assert(solution.maxNumberOfBalloons(givenText) == expectedAnswer);

    return 0;
}
