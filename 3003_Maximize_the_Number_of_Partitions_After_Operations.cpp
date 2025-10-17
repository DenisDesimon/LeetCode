//#3003 Maximize the Number of Partitions After Operations - https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
        int n = s.size();
        vector<vector<int>> left(n, vector<int>(3)), right(n, vector<int>(3));
        int mask = 0, partitions = 0, uniqueLetters = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int curLetter = (1 << (s[i] - 'a'));
            if(!(mask & curLetter))
            {
                uniqueLetters++;
                mask |= curLetter;
                if(uniqueLetters > k)
                {
                    partitions++;
                    mask = curLetter;
                    uniqueLetters = 1;
                }
            }
            left[i + 1][0] = partitions;
            left[i + 1][1] = mask;
            left[i + 1][2] = uniqueLetters;
        }
        mask = 0, partitions = 0, uniqueLetters = 0;
        for(int i = n - 1; i > 0; i--)
        {
            int curLetter = (1 << (s[i] - 'a'));
            if(!(mask & curLetter))
            {
                uniqueLetters++;
                mask |= curLetter;
                if(uniqueLetters > k)
                {
                    partitions++;
                    mask = curLetter;
                    uniqueLetters = 1;
                }
            }
            right[i - 1][0] = partitions;
            right[i - 1][1] = mask;
            right[i - 1][2] = uniqueLetters;
        }
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            partitions = left[i][0] + right[i][0] + 2;
            mask = left[i][1] | right[i][1];
            uniqueLetters = 0;
            while(mask)
            {
                uniqueLetters++;
                mask &= (mask - 1);
            }
            if(left[i][2] == k && right[i][2] == k && uniqueLetters < 26)
                partitions++;
            else if(min(uniqueLetters + 1, 26) <= k)
                partitions--;
            result = max(result, partitions);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "accca";
    int givenk = 2;
    int expectedAnswer = 3;
    assert(solution.maxPartitionsAfterOperations(givenS, givenk) == expectedAnswer);

    givenS = "aabaab";
    givenk = 3;
    expectedAnswer = 1;
    assert(solution.maxPartitionsAfterOperations(givenS, givenk) == expectedAnswer);


    return 0;
}
