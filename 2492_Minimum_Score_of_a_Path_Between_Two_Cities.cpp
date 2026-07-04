//#2492 Minimum Score of a Path Between Two Cities - https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
    int find(int cur, vector<int> &parents){
        if(parents[cur] == -1)
            return cur;
        return parents[cur] = find(parents[cur], parents);
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int result = INT_MAX;
        vector<int> parents(n + 1, -1);
        for(auto &road : roads)
        {
            int parentLeft = find(road[0], parents);
            int parentRight = find(road[1], parents);
            if (parentLeft != parentRight)
                parents[parentRight] = parentLeft;
        }
        int root = find(1, parents);
        for(auto &road : roads)
        {
            if(find(road[0], parents) == root)
                result = min(result, road[2]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenRoads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    int givenN = 10;
    int expectedAnswer = 5;
    assert(solution.minScore(givenN, givenRoads) == expectedAnswer);

    givenRoads = {{1, 2, 2}, {1, 3, 4}, {3, 4,7}};
    givenN = 4;
    expectedAnswer = 2;
    assert(solution.minScore(givenN, givenRoads) == expectedAnswer);

    return 0;
}
