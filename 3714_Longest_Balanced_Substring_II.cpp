//#3714 Longest Balanced Substring II - https://leetcode.com/problems/longest-balanced-substring-ii/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int result = 0;
        int n = s.size();
        auto key = [&](int t, int x, int y){
            return (long long)t << 40 | (long long)(x + 200000) << 20 | (y + 200000);
        };
        unordered_map<long long, int> idxStart;
        int prefix[3] = {0};
        for(int i = 0; i <= n; i++)
        {
            if(i)
                prefix[s[i - 1] - 'a']++;
            int a = prefix[0];
            int b = prefix[1];
            int c = prefix[2];
            long long subs[7] = {
                key(0, a - b, a - c), //abc
                key(1, a - b, c), //ab
                key(2, a - c, b), //ac
                key(3, b - c, a), //bc
                key(4, b, c), //a
                key(5, a, c), //b
                key(6, a, b) //c
            };
            for(auto &key : subs)
            {
                if(idxStart.count(key))
                    result = max(result, i - idxStart[key]);
                else
                    idxStart[key] = i;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "abbac";
    int expectedAnswer = 4;
    assert(solution.longestBalanced(givenS) == expectedAnswer);

    givenS = "aabcc";
    expectedAnswer = 3;
    assert(solution.longestBalanced(givenS) == expectedAnswer);

    return 0;
}
