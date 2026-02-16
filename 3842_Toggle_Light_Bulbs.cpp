//#3842 Toggle Light Bulbs - https://leetcode.com/problems/toggle-light-bulbs/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        bool isOn[101] = {false};
        for(auto &bulb : bulbs)
        {
            isOn[bulb] = !isOn[bulb];
        }
        vector<int> result;
        for(int i = 1; i < 101; i++)
        {
            if(isOn[i])
                result.push_back(i);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenBulbs = {10, 30, 20, 10};
    vector<int> expectedAnswer = {20, 30};
    assert(solution.toggleLightBulbs(givenBulbs) == expectedAnswer);

    givenBulbs = {100, 100};
    expectedAnswer = {};
    assert(solution.toggleLightBulbs(givenBulbs) == expectedAnswer);

    return 0;
}
