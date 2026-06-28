//#3960 Frequency Balance Subarray - https://leetcode.com/problems/frequency-balance-subarray/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int getLength(vector<int>& nums) {
        int result = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            unordered_map<int, int> freq;
            unordered_map<int, int> freqCount;
            int maxFreq = 0;
            for(int j = i; j < n; j++)
            {
                int num = nums[j];
                int prevFreq = freq[num];
                if(prevFreq > 0)
                {
                    freqCount[prevFreq]--;
                    if(freqCount[prevFreq] == 0)
                        freqCount.erase(prevFreq);
                }

                int nextFreq = ++freq[num];
                freqCount[nextFreq]++;
                maxFreq = max(maxFreq, nextFreq);

                if(j - i + 1 == 1 || freqCount.size() > 2)
                    continue;

                if((maxFreq % 2 == 0 && freqCount.count(maxFreq / 2)) || (freqCount.size() == 1 && freqCount[maxFreq] == 1))
                {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenNums = {1, 2, 2, 1, 2, 3, 3, 3};
    int expectedAnswer = 5;
    assert(solution.getLength(givenNums) == expectedAnswer);

    givenNums = {5, 5, 5, 5};
    expectedAnswer = 4;
    assert(solution.getLength(givenNums) == expectedAnswer);

    return 0;
}
