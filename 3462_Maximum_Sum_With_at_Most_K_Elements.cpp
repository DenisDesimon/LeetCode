#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution{
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k){
        priority_queue<pair<int, int>, vector<pair<int, int>>> topNums;
        long long result = 0;
        for(int i = 0; i < (int)grid.size(); i++)
        {
            for(auto &num : grid[i])
            {
                topNums.emplace(num, i);
            }
        }
        while(k)
        {
            pair<int, int> num = topNums.top();
            topNums.pop();
            if(limits[num.second])
            {
                result += num.first;
                limits[num.second]--;
                k--;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_grid = {{1, 2}, {3, 4}};
    vector<int> given_limits = {1, 2};
    int given_k = 2;
    int  expected_answer = 7;
    assert(solution.maxSum(given_grid, given_limits, given_k) == expected_answer);

    given_grid = {{5, 3, 7}, {8, 2, 6}};
    given_limits = {2, 2};
    given_k = 3;
    expected_answer = 21;
    assert(solution.maxSum(given_grid, given_limits, given_k) == expected_answer);

    return 0;
}
