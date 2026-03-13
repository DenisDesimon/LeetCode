//#3863 Minimum Operations to Sort a String - https://leetcode.com/problems/minimum-operations-to-sort-a-string/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        char minLetter = 'z', maxLetter = 'a', prev = s[0];
        bool isSorted = true;
        for(int i = 1; i < n - 1; i++)
        {
            minLetter = min(minLetter, s[i]);
            maxLetter = max(maxLetter, s[i]);
            if(s[i] < prev)
                isSorted = false;
            prev = s[i];
        }
        if(isSorted && s[n - 1] >= prev)
            return 0;
        if(n == 2)
            return - 1;
        if(s[0] <= s[n - 1] && (s[0] <= minLetter || s[n - 1] >= maxLetter))
            return 1;
        return s[0] > maxLetter && s[n - 1] < minLetter ? 3 : 2;
    }
};

int main()
{
    Solution solution;
    string givenS = "oool";
    int expectedAnswer = 2;
    assert(solution.minOperations(givenS) == expectedAnswer);

    givenS = "jgg";
    expectedAnswer = 2;
    assert(solution.minOperations(givenS) == expectedAnswer);

    return 0;
}
