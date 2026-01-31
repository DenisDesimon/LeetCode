//#744 Find Smallest Letter Greater Than Target - https://leetcode.com/problems/find-smallest-letter-greater-than-target/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto iter = upper_bound(letters.begin(), letters.end(), target);
        return iter == letters.end() ? letters.front() : *iter;
    }
};

int main()
{
    Solution solution;
    vector<char> givenLetters = {'c', 'f', 'j'};
    char givenTarget = 'a';
    char expected_answer = 'c';
    assert(solution.nextGreatestLetter(givenLetters, givenTarget) == expected_answer);

    givenLetters = {'x', 'x', 'y', 'y'};
    givenTarget = 'z';
    expected_answer = 'x';
    assert(solution.nextGreatestLetter(givenLetters, givenTarget) == expected_answer);


    return 0;
}
