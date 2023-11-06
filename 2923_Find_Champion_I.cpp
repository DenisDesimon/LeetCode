//#2923 Find Champion I - https://leetcode.com/problems/find-champion-i/
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int i = 0;
        for(; i < (int)grid.size(); i++)
        {
            int j = 0;
            for(; j < (int)grid[0].size(); j++)
            {
                if(i == j)
                    continue;
                if(!grid[i][j])
                {
                    break;
                }
            }
            if(j == (int)grid.size())
                break;
        }
        return i;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{0 ,0, 1}, {1, 0, 1}, {0, 0, 0}};
    int  expected_answer = 1;
    cout<<(solution.findChampion(given_grid));
    assert(solution.findChampion(given_grid) == expected_answer);

    given_grid = {{0,1}, {0,0}};
    expected_answer = 0;
    assert(solution.findChampion(given_grid) == expected_answer);

    return 0;
}
