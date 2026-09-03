//#3876 Construct Uniform Parity Array II - https://leetcode.com/problems/construct-uniform-parity-array-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX, minEven = INT_MAX;
        for(auto &num : nums1)
        {
            if(num % 2)
                minOdd = min(minOdd, num);
            else
                minEven = min(minEven, num);
        }
        return minOdd == INT_MAX || minEven == INT_MAX || minOdd + 1 < minEven;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {2, 3};
    bool expectedAnswer = false;
    assert(solution.uniformArray(givenNums) == expectedAnswer);

    givenNums = {4, 6};
    expectedAnswer = true;
    assert(solution.uniformArray(givenNums) == expectedAnswer);


    return 0;
}
