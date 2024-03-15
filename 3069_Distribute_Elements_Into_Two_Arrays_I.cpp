//#3069 Distribute Elements Into Two Arrays I - https://leetcode.com/problems/distribute-elements-into-two-arrays-i/description/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums.front());
        arr2.push_back(nums[1]);
        for(int i = 2; i < (int)nums.size(); i++)
        {
            if(arr1.back() > arr2.back())
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};


int main()
{
    Solution solution;
    vector<int> given_nums = {2, 1, 3};
    vector<int> expected_answer = {2, 3, 1};
    assert(solution.resultArray(given_nums) == expected_answer);

    given_nums = {5, 4, 3, 8};
    expected_answer = {5, 3, 4, 8};
    assert(solution.resultArray(given_nums) == expected_answer);

    return 0;
}
