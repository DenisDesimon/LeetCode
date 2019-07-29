//#37 Sudoku Solver - https://leetcode.com/problems/sudoku-solver/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    void fill_Sudoku(int cur_col, int cur_row, vector<vector<bool>>& col, vector<vector<bool>>& row, vector<vector<bool>>& box, vector<vector<char>>& board, bool& if_soluton_found){
        if(cur_row == 9)
        {
            if_soluton_found = true;
            return;
        }
        else if (if_soluton_found)
            return;
        if(board[cur_row][cur_col] != '.')
        {
            if(cur_col != 8)
                fill_Sudoku(cur_col + 1, cur_row, col, row, box, board, if_soluton_found);
            else
                fill_Sudoku(0, cur_row + 1, col, row, box, board, if_soluton_found);
            return;
        }
        for(int i = 0; i < 9; i++)
        {
            if(col[cur_col][i] || row[cur_row][i] || box[cur_col / 3 + cur_row / 3 * 3][i] || if_soluton_found)
                continue;
            col[cur_col][i] = row[cur_row][i] = box[cur_col / 3 + cur_row / 3 * 3][i] = true;
            board[cur_row][cur_col] = '0' + i + 1;
            if(cur_col != 8)
                fill_Sudoku(cur_col + 1, cur_row, col, row, box, board, if_soluton_found);
            else
                fill_Sudoku(0, cur_row + 1, col, row, box, board, if_soluton_found);
            col[cur_col][i] = row[cur_row][i] = box[cur_col / 3 + cur_row / 3 * 3][i] = false;
            if(!if_soluton_found)
                board[cur_row][cur_col] = '.';
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col(9, vector<bool>(9, false)), row, box;
        bool if_soluton_found = false;
        box = row = col;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, num_box = i / 3 * 3 + j / 3;
                    col[j][num] = row[i][num] = box[num_box][num] = true;
                }
            }
        }
        fill_Sudoku(0, 0, col, row, box, board, if_soluton_found);
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
    vector<vector<char>> expected_answer =
        {{'5', '3', '4', '6', '7', '8', '9', '1', '2'},
         {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
         {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
         {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
         {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
         {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
         {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
         {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
         {'3', '4', '5', '2', '8', '6', '1', '7', '9'}};
    solution.solveSudoku(given_board);
    assert(given_board == expected_answer);

    return 0;
}
