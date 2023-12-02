//#2942 Find Words Containing Character - https://leetcode.com/problems/find-words-containing-character/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> result;
        for(int i = 0; i < (int)words.size(); i++)
        {
            for(int j = 0; j < (int)words[i].size(); j++)
            {
                if(words[i][j] == x)
                {
                    result.push_back(i);
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
    vector<string> given_words = {"wzppkd", "jxvk", "zaztizmwuv", "hvcdtobr"};
    char given_x = 'b';
    vector<int> expected_answer = {3};
    assert(solution.findWordsContaining(given_words, given_x) == expected_answer);

    given_words = {"leet", "code"};
    given_x = 'e';
    expected_answer = {0, 1};
    assert(solution.findWordsContaining(given_words, given_x) == expected_answer);

    return 0;
}
