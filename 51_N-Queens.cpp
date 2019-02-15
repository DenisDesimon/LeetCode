//#51 N-Queens - https://leetcode.com/problems/n-queens/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
    vector<vector<string>> result;
    void search(int row, int n, vector<bool> &column, vector<bool> &diag1, vector<bool> &diag2, vector<string> &field){

        if (row == n) {
         result.push_back(field);
         return;
                      }

        for (int col = 0; col < n; col++) {
            if (column[col]  || diag1[col + row]  || diag2[col -row + n - 1]) continue;
            field[row][col] = 'Q';
            column[col] = diag1[col + row] = diag2[col - row + n - 1] = true;
            search(row + 1, n, column, diag1, diag2, field);
            column[col] = diag1[col + row] = diag2[col - row + n - 1] = false;
            field[row][col] = '.';
                                    }

                                                                         }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> column(n, false);
        vector<bool> diag1(n * 2 - 1, false);
        vector<bool> diag2(n * 2 - 1, false);
        vector<string> field(n, string(n, '.'));

        search(0, n, column, diag1, diag2, field);
        return result;
    }
};

int main()
{
    Solution solution;
    int given_queens = 4;
    vector<vector<string>> expected_answer = {{".Q..","...Q","Q...","..Q."},{"..Q.", "Q...", "...Q", ".Q.."}};
    assert(solution.solveNQueens(given_queens) == expected_answer);

    return 0;
}
