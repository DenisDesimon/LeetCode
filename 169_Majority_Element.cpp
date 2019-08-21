//#169 Majority Element - https://leetcode.com/problems/majority-element/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(auto &num : nums)
        {
            hash[num]++;
            if(hash[num] > (int)nums.size() / 2)
                return num;
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {3, 2, 3};
    int expected_answer = 3;
    assert(solution.majorityElement(given_nums) == expected_answer);

    given_nums = {2, 2, 1, 1, 1, 2, 2};
    expected_answer = 2;
    assert(solution.majorityElement(given_nums) == expected_answer);

    return 0;
}
