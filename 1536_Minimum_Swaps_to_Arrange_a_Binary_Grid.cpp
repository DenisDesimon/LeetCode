//#1536 Minimum Swaps to Arrange a Binary Grid - https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> countZeroes(n, n);
        for(int i = 0; i < n; i++)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(grid[i][j])
                {
                    countZeroes[i] = n - j - 1;
                    break;
                }
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            int target = n - i - 1;
            if(countZeroes[i] >= target)
                continue;
            int j = i + 1;
            for(; j < n; j++)
            {
                if(countZeroes[j] >= target)
                {
                    for(int t = j - 1; t >= i; t--)
                    {
                        swap(countZeroes[t], countZeroes[t + 1]);
                        result++;
                    }
                    break;
                }
            }
            if(j == n)
                return -1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenGrid = {{0, 0, 1}, {1, 1, 0} ,{1, 0, 0}};
    int expectedAnswer = 3;
    assert(solution.minSwaps(givenGrid) == expectedAnswer);

    givenGrid = {{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}};
    expectedAnswer = -1;
    assert(solution.minSwaps(givenGrid) == expectedAnswer);

    return 0;
}
