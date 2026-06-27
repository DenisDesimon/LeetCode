//#3020 Find the Maximum Number of Elements in Subset - https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for(auto &num : nums)
            freq[num]++;
        int result = 0;
        if(freq[1] % 2 == 0)
            result = freq[1] - 1;
        else
            result = freq[1];
        freq.erase(1);
        for(auto[num, _] : freq)
        {
            int cur = 0;
            long long x = num;
            for(; freq.count(x) && freq[x] > 1; x *= x)
                cur += 2;
            result = max(result, cur + (freq.count(x) ? 1 : -1));
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {5, 4, 1, 2, 2};
    int expectedAnswer = 3;
    assert(solution.maximumLength(givenNums) == expectedAnswer);

    givenNums = {1, 3, 2, 4};
    expectedAnswer = 1;
    assert(solution.maximumLength(givenNums) == expectedAnswer);

    return 0;
}
