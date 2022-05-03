//#2239 Find Closest Number to Zero - https://leetcode.com/problems/find-closest-number-to-zero/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int dist = INT_MAX;
        for(auto num : nums)
        {
            if(abs(num) < abs(dist))
                dist = num;
            else if(abs(num) == abs(dist))
                dist = max(dist, num);
        }
        return dist;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {-4, -2, 1, 4, 8};
    int expected_answer = 1;
    assert(solution.findClosestNumber(given_nums) == expected_answer);

    given_nums = {2 -1, 1};
    expected_answer = 1;
    assert(solution.findClosestNumber(given_nums) == expected_answer);

    return 0;
}
