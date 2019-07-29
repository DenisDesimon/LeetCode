//#36 Valid Sudoku - https://leetcode.com/problems/valid-sudoku/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col(9, vector<bool>(9, false)), row, box;
        row = box = col;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, num_box = i / 3 * 3 + j / 3;
                    if(col[j][num] || row[i][num] || box[num_box][num])
                        return false;
                    col[j][num] = row[i][num] = box[num_box][num] = true;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<char>> given_board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    bool expected_answer = true;
    assert(solution.isValidSudoku(given_board) == expected_answer);

    return 0;
}
