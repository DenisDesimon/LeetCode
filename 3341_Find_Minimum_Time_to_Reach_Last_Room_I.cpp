//#3341 Find Minimum Time to Reach Last Room I - https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minCurrentDoor;
        minCurrentDoor.push({0, 0, 0});
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> currentDoor;
        while(!minCurrentDoor.empty())
        {
            currentDoor = minCurrentDoor.top();
            minCurrentDoor.pop();
            if(visited[currentDoor[1]][currentDoor[2]])
                continue;
            if(currentDoor[1] == n - 1 && currentDoor[2] == m - 1)
                break;
            visited[currentDoor[1]][currentDoor[2]] = 1;
            for(int i = 0; i < 4; i++)
            {
                int x = currentDoor[1] + directions[i][0];
                int y = currentDoor[2] + directions[i][1];
                if(x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if(!visited[x][y])
                    minCurrentDoor.push({max(currentDoor[0], moveTime[x][y]) + 1, x, y});
            }

        }
        return currentDoor.front();
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_moveTime = {{0, 4}, {4, 4}};
    int expected_answer = 6;
    assert(solution.minTimeToReach(given_moveTime) == expected_answer);

    given_moveTime = {{0, 1}, {1, 2}};
    expected_answer = 3;
    assert(solution.minTimeToReach(given_moveTime) == expected_answer);

    return 0;
}
