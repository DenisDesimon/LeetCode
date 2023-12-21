//#2965 Find Missing and Repeated Values - https://leetcode.com/problems/find-missing-and-repeated-values/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> result(2);
        unordered_map<int, int> hash;
        int size = grid.size() * grid.size();
        for(auto &row : grid)
        {
            for(auto &num : row)
            {
                hash[num]++;
            }
        }
        for(int i = 1; i <= size; i ++)
        {
            if(hash[i] == 0)
                result[1] = i;
            else if(hash[i] >= 2)
                result[0] = i;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{1, 3}, {2, 2}};
    vector<int> expected_answer = {2, 4};
    assert(solution.findMissingAndRepeatedValues(given_grid) == expected_answer);

    given_grid = {{9, 1, 7}, {8, 9, 2}, {3, 4, 6}};
    expected_answer = {9, 5};
    assert(solution.findMissingAndRepeatedValues(given_grid) == expected_answer);

    return 0;
}
