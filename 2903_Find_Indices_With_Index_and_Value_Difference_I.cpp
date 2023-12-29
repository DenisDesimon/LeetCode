//#2903 Find Indices With Index and Value Difference I - https://leetcode.com/problems/find-indices-with-index-and-value-difference-i/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        for(int i = 0; i < (int)nums.size(); i++)
        {
            for(int j = 0; j < (int)nums.size(); j++)
            {
                if(abs(i - j) >= indexDifference && abs(nums[i] - nums[j]) >= valueDifference)
                    return {i, j};
            }
        }
        return {-1, -1};
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {5, 1, 4, 1};
    int indexDifference = 2;
    int valueDifference = 4;
    vector<int> expected_answer = {0, 3};
    assert(solution.findIndices(given_nums, indexDifference, valueDifference) == expected_answer);

    given_nums = {2, 1};
    indexDifference = 0;
    valueDifference = 0;
    expected_answer = {0, 0};
    assert(solution.findIndices(given_nums, indexDifference, valueDifference) == expected_answer);

    return 0;
}
