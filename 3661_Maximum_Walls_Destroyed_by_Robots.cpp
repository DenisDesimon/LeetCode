//#3661 Maximum Walls Destroyed by Robots - https://leetcode.com/problems/maximum-walls-destroyed-by-robots/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        int m = walls.size();
        vector<int> wallsToLeft(n), wallsToRight(n), wallsInBetween(n);
        unordered_map<int, int> robotsToDistance;
        for(int i = 0; i < n; i++)
            robotsToDistance[robots[i]] = distance[i];
        sort(robots.begin(), robots.end());
        sort(walls.begin(), walls.end());
        int rightIdx = 0, leftIdx = 0, curIdx = 0, wallsInBetweenStart = 0;
        for(int i = 0; i < n; i++)
        {
            while(rightIdx < m && robots[i] >= walls[rightIdx])
                rightIdx++;
            int leftStrikeEnd = rightIdx;

            while(curIdx < m && robots[i] > walls[curIdx])
                curIdx++;
            int rightStrikeStart = curIdx;

            int leftStrikeDis = (i > 0) ? max(robots[i] - robotsToDistance[robots[i]], robots[i - 1] + 1) : robots[i] - robotsToDistance[robots[i]];
            while(leftIdx < m && walls[leftIdx] < leftStrikeDis)
                leftIdx++;
            int leftStrikeStart = leftIdx;

            wallsToLeft[i] = leftStrikeEnd - leftStrikeStart;

            int rightStrikeDis = (i < n - 1) ? min(robots[i] + robotsToDistance[robots[i]], robots[i + 1] - 1) : robots[i] + robotsToDistance[robots[i]];
            while(rightIdx < m && walls[rightIdx] <= rightStrikeDis)
                rightIdx++;

            int rightStrikeEnd = rightIdx;

            wallsToRight[i] = rightStrikeEnd - rightStrikeStart;

            if(i == 0)
                continue;

            while(wallsInBetweenStart < m && robots[i - 1] > walls[wallsInBetweenStart])
                wallsInBetweenStart++;

            wallsInBetween[i] = leftStrikeEnd - wallsInBetweenStart;

        }

        int totalLastLeft = wallsToLeft[0], totalLastRight = wallsToRight[0];
        for(int i = 1; i < n; i++)
        {
            int curLastLeft = max(totalLastLeft + wallsToLeft[i], totalLastRight - wallsToRight[i - 1] +
                    min(wallsToRight[i - 1] + wallsToLeft[i], wallsInBetween[i]));
            int curLastRight = max(totalLastLeft, totalLastRight) + wallsToRight[i];
            totalLastLeft = curLastLeft;
            totalLastRight = curLastRight;
        }
        return max(totalLastLeft, totalLastRight);
    }
};



int main()
{
    Solution solution;
    vector<int> givenRobots = {1, 2};
    vector<int> givenDistance = {100, 1};
    vector<int> givenWalls = {10};
    int expectedAnswer = 0;
    assert(solution.maxWalls(givenRobots, givenDistance, givenWalls) == expectedAnswer);

    givenRobots = {10, 2};
    givenDistance = {5, 1};
    givenWalls = {5, 2, 7};
    expectedAnswer = 3;
    assert(solution.maxWalls(givenRobots, givenDistance, givenWalls) == expectedAnswer);

    return 0;
}
