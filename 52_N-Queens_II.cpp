//#52 N-Queens II - https://leetcode.com/problems/n-queens-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution {
    int result= 0;
    void search(int row, int n, vector<bool> &column, vector<bool> &diag1, vector<bool> &diag2){

        if (row == n) {
         result+=2;
         return;
                      }

        for (int col = 0; col < n; col++) {
            if ((row == 0 && col > (n - 1) / 2) ||  (column[(n - 1) / 2] && row == 1 && col > ((n - 1) / 2) && n%2 == 1) || column[col]  || diag1[col + row]  || diag2[col -row + n - 1]) continue;
            column[col] = diag1[col + row] = diag2[col - row + n - 1] = true;
            search(row + 1, n, column, diag1, diag2);
            column[col] = diag1[col + row] = diag2[col - row + n - 1] = false;
                                    }

                                                                                                    }
public:
     int totalNQueens(int n) {
         if(n == 1)
         return 1;
        vector<bool> column(n, false);
        vector<bool> diag1(n * 2 - 1, false);
        vector<bool> diag2(n * 2 - 1, false);

        search(0, n, column, diag1, diag2);
        return result;
    }
};

int main()
{
    Solution solution;
    int given_queens = 4;
    int expected_answer = 2;
    assert(solution.totalNQueens(given_queens) == expected_answer);

    return 0;
}
