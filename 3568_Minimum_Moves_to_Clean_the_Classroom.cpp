//#3568 Minimum Moves to Clean the Classroom - https://leetcode.com/problems/minimum-moves-to-clean-the-classroom/
#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;

struct point{
    int x, y, energy, mask;
};

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int startX, startY;
        int n = classroom.size();
        int m = classroom[0].size();
        int countLitter = 0;
        vector<vector<int>> mask(n, vector<int> (m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(classroom[i][j] == 'S')
                {
                    startX = i;
                    startY = j;
                }
                else if(classroom[i][j] == 'L')
                    mask[i][j] |= 1 << countLitter++;
            }
        }
        queue<point> classRooms;
        classRooms.push({startX, startY, energy, 0});
        vector<vector<vector<int>>> bestEnergy(n, vector<vector<int>>(m, vector<int>(1 << countLitter, -1)));
        bestEnergy[startX][startY][0] = energy;
        int moves = 0;
        while(!classRooms.empty())
        {
            int size = classRooms.size();
            while(size--)
            {
                point cur = classRooms.front();
                classRooms.pop();
                if(cur.mask == (1 << countLitter) - 1)
                    return moves;
                if(cur.energy == 0)
                    continue;
                for(auto &dir : dirs)
                {
                    int nextX = cur.x + dir[0];
                    int nextY = cur.y + dir[1];
                    if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m || classroom[nextX][nextY] == 'X')
                        continue;
                    int nextMask = cur.mask | mask[nextX][nextY];
                    int nextEnergy = classroom[nextX][nextY] == 'R' ? energy : cur.energy - 1;
                    if(nextEnergy > bestEnergy[nextX][nextY][nextMask])
                    {
                        bestEnergy[nextX][nextY][nextMask] = nextEnergy;
                        classRooms.push({nextX, nextY, nextEnergy, nextMask});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};


int main()
{
    Solution solution;
    vector<string> givenClassroom = {"S.", "XL"};
    int givenEnergy = 2;
    int expectedAnswer = 2;
    assert(solution.minMoves(givenClassroom, givenEnergy) == expectedAnswer);

    givenClassroom = {"LS", "RL"};
    givenEnergy = 4;
    expectedAnswer = 3;
    assert(solution.minMoves(givenClassroom, givenEnergy) == expectedAnswer);


    return 0;
}
