//#1477 Find Two Non-overlapping Sub-arrays Each With Target Sum - https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int sum = 0;
        vector<int> prevLen(n);
        unordered_map<int, int> prefixIdx;
        prefixIdx[0] = -1;
        int result = n + 1;
        int minLen = n;
        for(int right = 0; right < n; right++)
        {
            sum += arr[right];
            if(prefixIdx.count(sum - target))
            {
                int left = prefixIdx[sum - target];
                result = min(result, right - left + (left == -1 ? n : prevLen[left]));
                minLen = min(minLen, right - left);
            }
            prevLen[right] = minLen;
            prefixIdx[sum] = right;
        }
        return result == n + 1 ? -1 : result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenArr = {3, 2, 2, 4, 3};
    int givenTarget = 3;
    int expectedAnswer = 2;
    assert(solution.minSumOfLengths(givenArr, givenTarget) == expectedAnswer);

    givenArr = {7, 3, 4, 7};
    givenTarget = 7;
    expectedAnswer = 2;
    assert(solution.minSumOfLengths(givenArr, givenTarget) == expectedAnswer);


    return 0;
}
