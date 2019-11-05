//#957 Prison Cells After N Days - https://leetcode.com/problems/prison-cells-after-n-days/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> first_cell(8), next_cell(8);
        for(int i = 0; N--; i++)
        {
            for(int j = 1; j < 7; j++)
                next_cell[j] = cells[j - 1] == cells[j + 1];
            if(i == 0)
                first_cell = next_cell;
            else if(next_cell == first_cell)
                N %= i;
            cells = next_cell;
        }
        return cells;
    }
};

int main()
{
    Solution solution;
    vector<int> given_cells = {1, 0, 0, 1, 0, 0, 1, 0};
    int given_N = 1000000000;
    vector<int> expected_answer = {0, 0, 1, 1, 1, 1, 1, 0};
    assert(solution.prisonAfterNDays(given_cells, given_N) == expected_answer);

    given_cells = {0, 1, 0, 1, 1, 0, 0, 1};
    given_N = 7;
    expected_answer = {0, 0, 1, 1, 0, 0, 0, 0};
    assert(solution.prisonAfterNDays(given_cells, given_N) == expected_answer);

    return 0;
}
