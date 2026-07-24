//#3514 Number of Unique XOR Triplets II - https://leetcode.com/problems/number-of-unique-xor-triplets-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int size = 0;
        for(auto &num : nums)
            size |= num;
        vector<bool> second(size + 1), third(size + 1);
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                second[nums[i] ^ nums[j]] = true;
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < size + 1; j++)
            {
                if(second[j] == false)
                    continue;
                third[nums[i] ^ j] = true;
            }
        }
        int result = 0;
        for(int i = 0; i < size + 1; i++)
            result += third[i];
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {6, 7, 8, 9};
    int expectedAnswer = 4;
    assert(solution.uniqueXorTriplets(givenNums) == expectedAnswer);

    givenNums = {1, 3};
    expectedAnswer = 2;
    assert(solution.uniqueXorTriplets(givenNums) == expectedAnswer);

    return 0;
}
