//#1289 Minimum Falling Path Sum II - https://leetcode.com/problems/minimum-falling-path-sum-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        if(arr.size() == 1)
            return arr[0][0];
        pair<int, int> min_1st = {arr[0][0], 0}, min_2nd = {arr[0][1], 1};
        for(int i = 1; i < (int)arr[0].size(); i++)
        {
            if(min_1st.first > arr[0][i])
            {
                min_2nd = min_1st;
                min_1st = {arr[0][i], i};
            }
            else if(min_2nd.first > arr[0][i])
                min_2nd = {arr[0][i], i};
        }
        for(int i = 1; i < (int)arr.size(); i++)
        {
            pair<int, int> cur_min_1st = {INT_MAX, 0},
                    cur_min_2nd = {INT_MAX, 0};
            for(int j = 0; j < (int)arr[0].size(); j++)
            {
                int sum = arr[i][j] + (j == min_1st.second ? min_2nd.first : min_1st.first);
                if(cur_min_1st.first > sum)
                {
                    cur_min_2nd = cur_min_1st;
                    cur_min_1st = {sum, j};
                }
                else if(cur_min_2nd.first > sum)
                    cur_min_2nd = {sum, j};
            }
            min_1st = cur_min_1st;
            min_2nd = cur_min_2nd;

        }
        return min_1st.first;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int expected_answer = 13;
    assert(solution.minFallingPathSum(given_grid) == expected_answer);

    given_grid = {{-73, 61, 43, -48, -36}, {3, 30, 27, 57, 10}, {96, -76, 84, 59, -15},
                  {5, -49, 76, 31, -7}, {97, 91, 61, -46, 67}};
    expected_answer = -192;
    assert(solution.minFallingPathSum(given_grid) == expected_answer);

    return 0;
}
