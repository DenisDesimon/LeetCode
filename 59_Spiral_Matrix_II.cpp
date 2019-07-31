//#59 Spiral Matrix II - https://leetcode.com/problems/spiral-matrix-ii/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int count = 1;
        while(left <= right && top <= bottom)
        {
            for(int cur_left = left; cur_left <= right; cur_left++, count++)
                result[top][cur_left] = count;
            for(int cur_top = top + 1; cur_top <= bottom; cur_top++, count++)
                result[cur_top][right] = count;
            if(left < right && top < bottom)
            {
                for(int cur_right = right - 1; cur_right > left; cur_right--, count++)
                    result[bottom][cur_right] = count;
                for(int cur_bottom = bottom; cur_bottom > top; cur_bottom--, count++)
                {
                    result[cur_bottom][left] = count;
                }
            }
            left++, right--, top++, bottom--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 3;
    vector<vector<int>> expected_answer = {{1, 2, 3 },
                                           {8, 9, 4 },
                                           {7, 6, 5}};
    assert(solution.generateMatrix(given_n) == expected_answer);

    given_n = 2;
    expected_answer = {{1, 2},
                       {4, 3}};
    assert(solution.generateMatrix(given_n) == expected_answer);

    return 0;
}
