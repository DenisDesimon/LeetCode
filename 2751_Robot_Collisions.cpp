//#2751 Robot Collisions - https://leetcode.com/problems/robot-collisions/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, int>> robots(n);
        for(int i = 0; i < n; i++)
            robots[i] = {positions[i], i};
        sort(robots.begin(), robots.end());
        stack<pair<int, int>> leftRobots;
        for(auto robot : robots)
        {
            if(directions[robot.second] == 'R')
            {
                leftRobots.push(robot);
            }
            else
            {
                while(!leftRobots.empty())
                {
                    pair<int, int> left = leftRobots.top();
                    leftRobots.pop();
                    if(healths[left.second] > healths[robot.second])
                    {
                        healths[left.second]--;
                        healths[robot.second] = 0;
                        leftRobots.push(left);
                        break;
                    }else if(healths[left.second] < healths[robot.second])
                    {
                        healths[robot.second]--;
                        healths[left.second] = 0;
                    }
                    else
                    {
                        healths[robot.second] = 0;
                        healths[left.second] = 0;
                        break;
                    }
                }
            }
        }
        vector<int> result;
        for(int i = 0; i < n; i++)
        {
            if(healths[i] > 0)
                result.push_back(healths[i]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenPositions = {5, 4, 3, 2, 1};
    vector<int> givenHealths = {2, 17 ,9, 15, 10};
    string givenDirections = "RRRRR";
    vector<int> expectedAnswer = {2, 17, 9, 15, 10};
    assert(solution.survivedRobotsHealths(givenPositions, givenHealths, givenDirections) == expectedAnswer);

    givenPositions = {3, 5, 2, 6};
    givenHealths = {10, 10, 15, 12};
    givenDirections = "RLRL";
    expectedAnswer = {14};
    assert(solution.survivedRobotsHealths(givenPositions, givenHealths, givenDirections) == expectedAnswer);

    return 0;
}
