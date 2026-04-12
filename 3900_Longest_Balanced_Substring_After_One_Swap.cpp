//#3900 Longest Balanced Substring After One Swap - https://leetcode.com/problems/longest-balanced-substring-after-one-swap/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int result = 0, n = s.size();
        int prefix = 0;
        unordered_map<int, vector<int>> prefixPos;
        int countOnes = 0;
        prefixPos[0].push_back(-1);
        for(int i = 0; i < n; i++)
            countOnes += s[i] == '1';
        int countZeroes = n - countOnes;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '1')
            {
                prefix++;
            }
            else
            {
                prefix--;
            }
            if(prefixPos.count(prefix))
            {
                result = max(result, i - prefixPos[prefix].front());
            }
            prefixPos[prefix].push_back(i);
            if(prefixPos.count(prefix + 2))
            {
                for(int cur = 0; cur < (int)prefixPos[prefix + 2].size() && result < i - prefixPos[prefix + 2][cur]; cur++)
                {
                    if(countOnes - (i - prefixPos[prefix + 2][cur] - 2) / 2)
                        result = i - prefixPos[prefix + 2][cur];
                }
            }
            if(prefixPos.count(prefix - 2))
            {
                for(int cur = 0; cur < (int)prefixPos[prefix - 2].size() && result < i - prefixPos[prefix - 2][cur]; cur++)
                {
                    if(countZeroes - (i - prefixPos[prefix - 2][cur] - 2) / 2)
                        result = i - prefixPos[prefix - 2][cur];
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "100001";
    int expected_answer = 4;
    assert(solution.longestBalanced(givenS) == expected_answer);

    givenS = "01111100";
    expected_answer = 6;
    assert(solution.longestBalanced(givenS) == expected_answer);

    return 0;
}
