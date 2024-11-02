//#2490 Circular Sentence - https://leetcode.com/problems/circular-sentence/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if(sentence.front() != sentence.back())
            return false;
        for(int i = 1; i < (int)sentence.size(); i++)
        {
            if(sentence[i] == ' ' && sentence[i + 1] != sentence[i - 1])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;

    string given_sentence = "leetcode exercises sound delightful";
    bool expected_answer = true;
    assert(solution.isCircularSentence(given_sentence) == expected_answer);

    given_sentence = "Leetcode is cool";
    expected_answer = false;
    assert(solution.isCircularSentence(given_sentence) == expected_answer);

    return 0;
}
