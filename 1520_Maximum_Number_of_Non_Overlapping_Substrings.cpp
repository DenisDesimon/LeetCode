//#1520 Maximum Number of Non-Overlapping Substrings - https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/
#include <iostream>
#include <cassert>
#include <vector>
#include <deque>
#include <array>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int first[26], last[26], count[26] = {0};
        vector<int> order;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            int letter = s[i] - 'a';
            if(!count[letter])
            {
                first[letter] = i;
                order.push_back(letter);
            }
            count[letter]++;
            last[letter] = i;
        }
        vector<string> result;
        deque<array<int, 3>> interval;
        for(auto &letter : order)
        {
            interval.push_front({first[letter], last[letter], count[letter]});
            int sum = 0, left = INT_MAX, right = INT_MIN;
            for(auto &[start, end, freq] : interval)
            {
                sum += freq;
                left = min(left, start);
                right = max(right, end);
                if(right - left + 1 == sum)
                {
                    result.push_back(s.substr(left, right - left + 1));
                    interval.clear();
                    break;
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "adefaddaccc";
    vector<string> expectedAnswer = {"e", "f", "ccc"};
    assert(solution.maxNumOfSubstrings(givenS) == expectedAnswer);

    givenS = "abbaccd";
    expectedAnswer = {"bb", "cc", "d"};
    assert(solution.maxNumOfSubstrings(givenS) == expectedAnswer);


    return 0;
}
