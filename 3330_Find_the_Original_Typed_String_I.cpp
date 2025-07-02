//#3330 Find the Original Typed String I - https://leetcode.com/problems/find-the-original-typed-string-i/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int result = 0;
        for(int i = 1; i < (int)word.size(); i++)
        {
            if(word[i - 1] == word[i])
                result++;
        }
        return result + 1;
    }
};

int main()
{
    Solution solution;
    string given_word = "abbcccc";
    int expected_answer = 5;
    assert(solution.possibleStringCount(given_word) == expected_answer);

    given_word = "aaaa";
    expected_answer = 4;
    assert(solution.possibleStringCount(given_word) == expected_answer);

    return 0;
}
