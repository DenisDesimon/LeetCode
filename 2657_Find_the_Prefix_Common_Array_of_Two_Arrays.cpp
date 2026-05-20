//#2657 Find the Prefix Common Array of Two Arrays - https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int count = 0;
        int nums[51] = {false};
        int n = A.size();
        vector<int> result(n);
        for(int i = 0; i < n; i++)
        {
            if(nums[A[i]])
                count++;
            nums[A[i]] = true;
            if(nums[B[i]])
                count++;
            nums[B[i]] = true;
            result[i] = count;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenA  = {1, 3, 2, 4};
    vector<int> givenB  = {3, 1, 2, 4};
    vector<int> expectedAnswer = {0, 2, 3, 4};
    assert(solution.findThePrefixCommonArray(givenA, givenB) == expectedAnswer);

    givenA  = {2, 3, 1};
    givenB  = {3, 1, 2};
    expectedAnswer = {0, 1, 3};
    assert(solution.findThePrefixCommonArray(givenA, givenB) == expectedAnswer);

    return 0;
}
