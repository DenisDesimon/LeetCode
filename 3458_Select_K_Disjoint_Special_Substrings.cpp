//#3458 Select K Disjoint Special Substrings - https://leetcode.com/problems/select-k-disjoint-special-substrings/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution{
public:
    bool maxSubstringLength(string s, int k){
        vector<int> firstOccur(26, s.size());
        vector<int> lastOccur(26, -1);
        for(int i = 0; i < (int)s.size(); i++)
        {
            firstOccur[s[i] - 'a'] = min(i, firstOccur[s[i] - 'a']);
            lastOccur[s[i] - 'a'] = max(i, lastOccur[s[i] - 'a']);
        }
        vector<pair<int, int>> intervals;
        for(int left = 0; left < (int)s.size(); left++)
        {
            if(firstOccur[s[left] - 'a'] != left)
                continue;
            int right = lastOccur[s[left] - 'a'];
            bool flag = true;
            for(int i = left; i <= right; i++)
            {
                if(firstOccur[s[i] - 'a'] < left)
                {
                    flag = false;
                    break;
                }
                right = max(right, lastOccur[s[i] -'a']);
            }
            if(flag && !(left == 0 && right == (int)s.size() - 1))
                intervals.push_back({left, right});

        }
        sort(intervals.begin(), intervals.end(), [] (pair<int, int> a, pair<int, int> b) {return a.second < b.second;});
        int result = 0, prevEnd = -1;
        for(auto &interval : intervals)
        {
            if(interval.first > prevEnd)
                result++;
            prevEnd = interval.second;
        }
        return result >= k;
    }
};

int main()
{
    Solution solution;
    string givenS = "cdefdc";
    int  givenK = 2;
    bool expectedAnswer = true;
    assert(solution.maxSubstringLength(givenS, givenK) == expectedAnswer);


    givenS = "gyye";
    givenK = 3;
    expectedAnswer = true;
    assert(solution.maxSubstringLength(givenS, givenK) == expectedAnswer);

    return 0;
}
