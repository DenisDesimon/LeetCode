//#3016 Minimum Number of Pushes to Type Word II - https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int count[26] = {0};
        for(auto &letter : word)
            count[letter - 'a']++;
        sort(count, count + 26, greater<int>());
        int result = 0;
        int cost;
        for(int i = 0; i < 26; i++)
        {
            cost = i / 8 + 1;
            result += count[i] * cost;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenWord = "abcde";
    int expectedAnswer = 5;
    assert(solution.minimumPushes(givenWord) == expectedAnswer);

    givenWord = "xyzxyzxyzxyz";
    expectedAnswer = 12;
    assert(solution.minimumPushes(givenWord) == expectedAnswer);

    return 0;
}
