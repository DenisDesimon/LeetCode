//#3583 Count Special Triplets - https://leetcode.com/problems/count-special-triplets/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> numsCount;
        unordered_map<int, int> midTripletCount;
        int mod = 1e9 + 7;
        int result = 0;
        for(auto &num : nums)
        {
            if(num % 2 == 0)
                result = (result + midTripletCount[num]) % mod;
            midTripletCount[num * 2] = (midTripletCount[num * 2] + numsCount[num * 2]) % mod;
            numsCount[num]++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {6, 3, 6};
    int expectedAnswer = 1;
    assert(solution.specialTriplets(givenNums) == expectedAnswer);

    givenNums = {8, 4, 2, 8, 4};
    expectedAnswer = 2;
    assert(solution.specialTriplets(givenNums) == expectedAnswer);

    return 0;
}
