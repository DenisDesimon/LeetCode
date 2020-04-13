//#1253 Reconstruct a 2-Row Binary Matrix - https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/
#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> result;
        if(upper + lower != accumulate(colsum.begin(), colsum.end(), 0))
            return result;
        result.resize(2, vector<int>(colsum.size(), 0));
        for(int i = 0; i < (int)colsum.size(); i++)
        {
            if(colsum[i] == 0)
                continue;
            else if(colsum[i] == 2)
            {
                if(!lower || !upper)
                    return vector<vector<int>>(0);
                lower--;
                upper--;
                result[1][i]++;
                result[0][i]++;
            }
            else
            {
                if(lower > upper)
                {
                    lower--;
                    result[1][i]++;
                }
                else if(lower < upper)
                {
                    upper--;
                    result[0][i]++;
                }
                else
                {
                    if(!lower)
                        return vector<vector<int>>(0);
                    lower--;
                    result[1][i]++;
                }
            }

        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_colsum = {2, 1, 2, 2, 1, 1, 1};
    int given_upper = 4;
    int given_lower = 7;
    vector<vector<int>> expected_answer;
    assert(solution.reconstructMatrix(given_upper, given_lower, given_colsum) == expected_answer);

    given_colsum = {1, 1, 1};
    given_upper = 2;
    given_lower = 1;
    expected_answer = {{1, 0, 1}, {0, 1, 0}};
    assert(solution.reconstructMatrix(given_upper, given_lower, given_colsum) == expected_answer);

    return 0;
}
