//#2279 Maximum Bags With Full Capacity of Rocks - https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        priority_queue<int> subtraction;
        int result = 0;
        for(int i = 0; i < (int)capacity.size(); i++)
        {
            if(capacity[i] != rocks[i])
                subtraction.push(-(capacity[i] - rocks[i]));
            else
                result++;
        }
        while(!subtraction.empty() && -subtraction.top() <= additionalRocks)
        {
            additionalRocks += subtraction.top();
            result++;
            subtraction.pop();
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_capacity = {10, 2, 2};
    vector<int> given_rocks = {2, 2, 0};
    int given_additionalRocks = 100;
    int expected_answer = 3;
    assert(solution.maximumBags(given_capacity, given_rocks, given_additionalRocks) == expected_answer);

    given_capacity = {2, 3, 4, 5};
    given_rocks = {1, 2, 4, 4};
    given_additionalRocks = 2;
    expected_answer = 3;
    assert(solution.maximumBags(given_capacity, given_rocks, given_additionalRocks) == expected_answer);

    return 0;
}
