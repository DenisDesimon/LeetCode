//#3321 Find X-Sum of All K-Long Subarrays II - https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cassert>
using namespace std;

class Solution {
private:
    unordered_map<int, int> countNums;
    set<pair<int, int>> top, bot;
    int topMaxSize;
    long long curSum = 0;

    void add(int num){
        if(countNums.count(num))
            erase({countNums[num], num});
        countNums[num]++;
        insert({countNums[num], num});
    }

    void insert(pair<int, int> numFreq){
        if((int)top.size() < topMaxSize || numFreq > *(top.begin()))
        {
            top.insert(numFreq);
            curSum += (long long)numFreq.first * numFreq.second;
            if((int)top.size() > topMaxSize)
            {
                curSum -= (long long)(*top.begin()).first * (*top.begin()).second;
                bot.insert(*top.begin());
                top.erase(*top.begin());
            }
        }
        else
            bot.insert(numFreq);

    }
    void remove(int num){
        erase({countNums[num], num});
        countNums[num]--;
        if(countNums[num])
            insert({countNums[num], num});
    }
    void erase(pair<int, int> numFreq)
    {
        if(numFreq >= *top.begin())
        {
            curSum -= (long long)numFreq.first * numFreq.second;
            top.erase(numFreq);
            if(!bot.empty())
            {
                curSum += (long long)(*bot.rbegin()).first * (*bot.rbegin()).second;
                top.insert(*bot.rbegin());
                bot.erase(*bot.rbegin());
            }
        }
        else
            bot.erase(numFreq);
    }
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        curSum = 0;
        countNums.clear();
        top.clear(), bot.clear();
        topMaxSize = x;
        vector<long long> result;
        int n = nums.size();
        for(int i = 0; i < k - 1; i++)
            add(nums[i]);
        for(int i = 0; i < n - k + 1; i++)
        {
            add(nums[i + k - 1]);
            result.push_back(curSum);
            remove(nums[i]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 1, 2, 2, 3, 4, 2, 3};
    int givenK = 6;
    int givenN = 2;
    vector<long long> expectedAnswer = {6, 10, 12};
    assert(solution.findXSum(givenNums, givenK, givenN) == expectedAnswer);

    givenNums = {3, 8, 7, 8, 7, 5};
    givenK = 2;
    givenN = 2;
    expectedAnswer = {11, 15, 15, 15, 12};
    assert(solution.findXSum(givenNums, givenK, givenN) == expectedAnswer);

    return 0;
}
