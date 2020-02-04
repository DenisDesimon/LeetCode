//#1331 Rank Transform of an Array - https://leetcode.com/problems/rank-transform-of-an-array/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> hash;
        vector<int> sorted_arr(arr);
        sort(sorted_arr.begin(), sorted_arr.end());
        for(auto& num : sorted_arr)
        {
            if(!hash.count(num))
                hash[num] = hash.size() + 1;
        }
        for(auto& num : arr)
            num = hash[num];
        return arr;
    }
};

int main()
{
    Solution solution;
    vector<int> given_arr = {40, 10, 20, 30};
    vector<int> expected_answer = {4, 1, 2, 3};
    assert(solution.arrayRankTransform(given_arr) == expected_answer);

    given_arr = {100, 100, 100};
    expected_answer = {1, 1, 1};
    assert(solution.arrayRankTransform(given_arr) == expected_answer);

    return 0;
}
