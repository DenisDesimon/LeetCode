//#3433 Count Mentions Per User - https://leetcode.com/problems/count-mentions-per-user/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](vector<string> &left, vector<string> &right)
        {if(stoi(left[1]) == stoi(right[1]))
                return left[0] > right[0];
        return stoi(left[1]) < stoi(right[1]);});
        vector<int> result(numberOfUsers);
        vector<int> onlineTime(numberOfUsers);
        for(auto &event : events)
        {
            if(event[2] == "ALL")
            {
                for(int i = 0; i < numberOfUsers; i++)
                {
                    result[i]++;
                }
                continue;
            }
            if(event[2] == "HERE")
            {
                for(int i = 0; i < (int)onlineTime.size(); i++)
                {
                    if(onlineTime[i] <= stoi(event[1]))
                        result[i]++;
                }
                continue;
            }
            if(event[0] == "MESSAGE")
            {
                int curUser = 0;
                for(int j = 2; j < (int)event[2].size(); )
                {
                    if(event[2][j] == ' ')
                    {
                        result[curUser]++;
                        curUser = 0;
                        j += 3;
                        continue;
                    }
                    curUser = curUser * 10 + (event[2][j] - '0');
                    j++;
                }
                result[curUser]++;
            }
            else if(event[0] == "OFFLINE")
            {
                onlineTime[stoi(event[2])] = stoi(event[1]) + 60;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenN = 2;
    vector<vector<string>> givenEvents = {{"MESSAGE","10","id1 id0"}, {"OFFLINE", "11", "0"}, {"MESSAGE", "71", "HERE"}};
    vector<int> expectedAnswer = {2, 2};
    assert(solution.countMentions(givenN, givenEvents) == expectedAnswer);

    givenN = 3;
    givenEvents = {{"MESSAGE", "2", "HERE"},{"OFFLINE", "2", "1"}, {"OFFLINE", "1", "0"}, {"MESSAGE", "61", "HERE"}};
    expectedAnswer = {1, 0, 2};
    assert(solution.countMentions(givenN, givenEvents) == expectedAnswer);

    return 0;
}
