//#3921 Score Validator - https://leetcode.com/problems/score-validator/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, count = 0;
        for(auto &event : events)
        {
            if(event == "WD" || event == "NB")
                score++;
            else if(event == "W")
                count++;
            else
                score += event[0] - '0';
            if(count == 10)
                break;
        }
        return {score, count};
    }
};

int main()
{
    Solution solution;
    vector<string> givenEvents  = {"1", "4", "W", "6", "WD"};
    vector<int> expectedAnswer = {12, 1};
    assert(solution.scoreValidator(givenEvents) == expectedAnswer);

    givenEvents = {"WD", "NB", "0", "4", "4"};
    expectedAnswer = {10, 0};
    assert(solution.scoreValidator(givenEvents) == expectedAnswer);

    return 0;
}
