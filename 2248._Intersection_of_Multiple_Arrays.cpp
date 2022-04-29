//#2248 Intersection of Multiple Arrays - https://leetcode.com/problems/intersection-of-multiple-arrays/
#include <iostream>
#include <map>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        map<int, int> hash;
        vector<int> result;
        for(auto array : nums)
        {
            for(auto num : array)
                hash[num]++;
        }
        for(auto num : hash)
        {
            if(num.second == (int)nums.size())
                result.push_back(num.first);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_array = {{3, 1, 2, 4, 5}, {1, 2, 3, 4}, {3, 4, 5, 6}};
    vector<int> expected_answer = {3, 4};
    assert(solution.intersection(given_array) == expected_answer);

    given_array = {{1, 2, 3}, {4, 5, 6}};
    expected_answer = {};
    assert(solution.intersection(given_array) == expected_answer);

    return 0;
}
