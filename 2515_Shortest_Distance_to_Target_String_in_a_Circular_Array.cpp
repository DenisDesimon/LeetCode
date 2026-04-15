//#2515 Shortest Distance to Target String in a Circular Array - https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        for(int i = 0; i < n; i++)
        {
            if(words[(startIndex - i + n) % n] == target)
                return i;
            if(words[(startIndex + i) % n] == target)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<string> givenWords = {"hello", "i", "am", "leetcode", "hello"};
    string givenTarget = "hello";
    int givenStartIndex = 1;
    int expectedAnswer = 1;
    assert(solution.closestTarget(givenWords, givenTarget, givenStartIndex) == expectedAnswer);

    givenWords = {"i", "eat", "leetcode"};
    givenTarget = "ate";
    givenStartIndex = 0;
    expectedAnswer = -1;
    assert(solution.closestTarget(givenWords, givenTarget, givenStartIndex) == expectedAnswer);

    return 0;
}
