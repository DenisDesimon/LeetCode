//#134 Gas Station - https://leetcode.com/problems/gas-station/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int result = 0, local_diff = 0, total_diff = 0;
        for(int i = 0; i < (int)gas.size(); i++)
        {
            local_diff += gas[i] - cost[i];
            total_diff += gas[i] - cost[i];
            if(local_diff < 0)
            {
                result = i + 1;
                local_diff = 0;
            }
        }
        if(total_diff < 0)
            return - 1;
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_gas = {3, 1, 1};
    vector<int> given_cost = {1, 2, 2};
    int expected_answer = 0;
    assert(solution.canCompleteCircuit(given_gas, given_cost) == expected_answer);

    given_gas = {1, 2, 3, 4, 5};
    given_cost = {3, 4, 5, 1, 2};
    expected_answer = 3;
    assert(solution.canCompleteCircuit(given_gas, given_cost) == expected_answer);

    return 0;
}
