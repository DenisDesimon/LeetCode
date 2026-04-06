//#874 Walking Robot Simulation - https://leetcode.com/problems/walking-robot-simulation/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> obsPairs;
        int multiHash = 7e4;
        for(auto &obstacle : obstacles)
        {
            obsPairs.insert(obstacle[0] * multiHash + obstacle[1]);
        }
        int result = 0;
        pair<int, int> directions[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pair<int, int> curPos;
        int curDir = 0;
        for(auto &command : commands)
        {
            if(command < 0)
            {
                if(command == -1)
                    curDir = (curDir + 1) % 4;
                else
                    curDir = (curDir - 1 + 4) % 4;
            }
            else
            {
                for(int i = 0; i < command; i++)
                {
                    pair<int, int> nextPos = {curPos.first + directions[curDir].first, curPos.second + directions[curDir].second};
                    if(obsPairs.count(nextPos.first * multiHash + nextPos.second))
                        break;
                    int distance = nextPos.first * nextPos.first + nextPos.second * nextPos.second;
                    curPos = nextPos;
                    result = max(result, distance);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenCommands = {4, -1, 3};
    vector<vector<int>> givenObstacles = {};
    int expectedAnswer = 25;
    assert(solution.robotSim(givenCommands, givenObstacles) == expectedAnswer);

    givenCommands = {4, -1, 4, -2, 4};
    givenObstacles = {{2, 4}};
    expectedAnswer = 65;
    assert(solution.robotSim(givenCommands, givenObstacles) == expectedAnswer);

    return 0;
}
