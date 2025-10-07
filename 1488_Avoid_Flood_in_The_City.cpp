//#1488 Avoid Flood in The City - https://leetcode.com/problems/avoid-flood-in-the-city/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int, int> rainIdx;
        set<int> dryDays;
        vector<int> result(rains.size(), 1);
        for(int i = 0; i < (int)rains.size(); i++)
        {
            if(rains[i] == 0)
            {
                dryDays.insert(i);
                continue;
            }
            result[i] = -1;
            if(rainIdx.count(rains[i]))
            {
                auto dryDay = dryDays.upper_bound(rainIdx[rains[i]]);
                if(dryDay == dryDays.end())
                    return {};
                result[*dryDay] = rains[i];
                dryDays.erase(dryDay);
            }
            rainIdx[rains[i]] = i;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenRains = {1, 2, 3, 4};
    vector<int> expectedAnswer = {-1, -1, -1, -1};
    assert(solution.avoidFlood(givenRains) == expectedAnswer);

    givenRains = {1, 2, 0, 0, 2, 1};
    expectedAnswer = {-1, -1, 2, 1, -1, -1};
    assert(solution.avoidFlood(givenRains) == expectedAnswer);

    return 0;
}
