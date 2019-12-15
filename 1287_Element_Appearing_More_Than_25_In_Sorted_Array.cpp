//#1287 Element Appearing More Than 25% In Sorted Array - https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int, int> hash;
        double bound = arr.size() / 4;
        for(auto& num : arr)
        {
            hash[num]++;
            if((double)hash[num] > bound)
                return num;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> given_arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    int expected_answer = 6;
    assert(solution.findSpecialInteger(given_arr) == expected_answer);

    given_arr = {1};
    expected_answer = 1;
    assert(solution.findSpecialInteger(given_arr) == expected_answer);

    return 0;
}
