//#3296 Minimum Number of Seconds to Make Mountain Height Zero - https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        for(auto &wt : workerTimes)
            pq.push({wt, wt, 1});
        long long result = 0;
        while(mountainHeight)
        {
            mountainHeight--;
            auto [time, cost, toDo] = pq.top();
            result = max(result, time);
            pq.pop();
            time += (long long)++toDo * cost;
            pq.push({time, cost, toDo});
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int givenMountainHeight = 4;
    vector<int> givenWorkerTimes = {2, 1, 1};
    long long expectedAnswer = 3;
    assert(solution.minNumberOfSeconds(givenMountainHeight, givenWorkerTimes) == expectedAnswer);

    givenMountainHeight = 10;
    givenWorkerTimes = {3, 2, 2, 4};
    expectedAnswer = 12;
    assert(solution.minNumberOfSeconds(givenMountainHeight, givenWorkerTimes) == expectedAnswer);

    return 0;
}
