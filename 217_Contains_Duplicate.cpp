//#217 Contains Duplicate - https://leetcode.com/problems/contains-duplicate/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto &num : nums)
        {
            if(hash.count(num))
                return true;
            hash.insert(num);
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> given_nums = {1, 2, 3, 4};
    bool expected_answer = false;
    assert(solution.containsDuplicate(given_nums) == expected_answer);

    given_nums = {1, 2, 3, 1};
    expected_answer = true;
    assert(solution.containsDuplicate(given_nums) == expected_answer);

    return 0;
}
