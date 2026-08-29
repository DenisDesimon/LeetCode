//#2948 Make Lexicographically Smallest Array by Swapping Elements - https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
#include <iostream>
#include <cassert>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        unordered_map<int, int> numToGroup;
        vector<vector<int>> groupToBucket;
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        int curGroup = 0;
        numToGroup[sortedNums.front()] = curGroup;
        groupToBucket.push_back({sortedNums.front()});
        int n = nums.size();
        for(int i = 1; i < n; i++)
        {
            if(sortedNums[i] - limit > sortedNums[i - 1])
            {
                curGroup++;
                groupToBucket.push_back({});
            }
            numToGroup[sortedNums[i]] = curGroup;
            groupToBucket[curGroup].push_back(sortedNums[i]);
        }
        vector<int> idxs(groupToBucket.size(), 0);
        for(int i = 0; i < n; i++)
        {
            curGroup = numToGroup[nums[i]];
            nums[i] = groupToBucket[curGroup][idxs[curGroup]];
            idxs[curGroup]++;
        }
        return nums;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 5, 3, 9, 8};
    int givenLimit = 2;
    vector<int> expectedAnswer = {1, 3, 5, 8, 9};
    assert(solution.lexicographicallySmallestArray(givenNums, givenLimit) == expectedAnswer);

    givenNums = {1, 7, 6, 18, 2, 1};
    givenLimit = 3;
    expectedAnswer = {1, 6, 7, 18, 1, 2};
    assert(solution.lexicographicallySmallestArray(givenNums, givenLimit) == expectedAnswer);


    return 0;
}
