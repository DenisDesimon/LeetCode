//#756 Pyramid Transition Matrix - https://leetcode.com/problems/pyramid-transition-matrix/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    bool solve(int cur_col, int cur_row, int num_cols, vector<vector<int>>& pyramid, vector<vector<int>>& allow)
    {
        if(cur_row == 0 && cur_col == 1)
            return true;
        else if(cur_col == num_cols)
        {
            return solve(0, cur_row - 1, num_cols - 1, pyramid, allow);
        }
        else
        {
            for(int i = 0; i <= 7; i++)
            {
                if(allow[pyramid[cur_row + 1][cur_col]][pyramid[cur_row + 1][cur_col + 1]] & (1 << i))
                {
                    pyramid[cur_row][cur_col] = i;
                    if(solve(cur_col + 1, cur_row, num_cols, pyramid, allow))
                        return true;
                }
            }
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        vector<vector<int>> allow(7, vector<int>(7));
        int N = bottom.size();
        vector<vector<int>> pyramid(N, vector<int>(N));
        for(auto triple : allowed)
            allow[triple[0] - 'A'][triple[1] - 'A'] |= 1 << (triple[2] - 'A');
        for(int i = 0; i < N; i++)
        {
            pyramid[N - 1][i] = bottom[i] - 'A';
        }
        return solve(0, N - 2, N - 1, pyramid, allow);
    }
};

int main()
{
    Solution solution;
    string given_bottom = "AABA";
    vector<string> given_allowed = {"AAA", "AAB", "ABA", "ABB", "BAC"};
    bool expected_answer = false;
    assert(solution.pyramidTransition(given_bottom, given_allowed) == expected_answer);

    given_bottom = "BCD";
    given_allowed = {"BCG", "CDE", "GEA", "FFF"};
    expected_answer = true;
    assert(solution.pyramidTransition(given_bottom, given_allowed) == expected_answer);


    return 0;
}
