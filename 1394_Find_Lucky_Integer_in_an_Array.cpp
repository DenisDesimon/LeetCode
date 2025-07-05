//#1394 Find Lucky Integer in an Array - https://leetcode.com/problems/find-lucky-integer-in-an-array/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> frequency;
        int result = -1;
        for(auto &num : arr)
            frequency[num]++;
        for(auto &freq : frequency)
        {
            if(freq.first == freq.second)
                result = max(result, freq.second);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_arr = {2, 2, 3, 4};
    int expected_answer = 2;
    assert(solution.findLucky(given_arr) == expected_answer);

    given_arr = {1, 2, 2, 3, 3, 3};
    expected_answer = 3;
    assert(solution.findLucky(given_arr) == expected_answer);

    return 0;
}

