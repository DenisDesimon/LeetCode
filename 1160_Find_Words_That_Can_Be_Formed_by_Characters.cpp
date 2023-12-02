//#1160 Find Words That Can Be Formed by Characters - https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int alphabet[26] = {};
        int result = 0;
        for(auto &letter: chars)
        {
            alphabet[letter - 'a']++;
        }
        for(auto &word: words)
        {
            int count_letters[26] = {};
            int i = 0;
            for(; i < (int)word.size(); i++)
            {
                count_letters[word[i] - 'a']++;
                if(count_letters[word[i] - 'a'] > alphabet[word[i] - 'a'])
                    break;
            }
            if(i == (int)word.size())
                result += (int)word.size();
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> given_words = {"cat", "bt", "hat", "tree"};
    string given_chars  = "atach";
    int expected_answer = 6;
    assert(solution.countCharacters(given_words, given_chars) == expected_answer);

    given_words = {"hello", "world", "leetcode"};
    given_chars  = "welldonehoneyr";
    expected_answer = 10;
    assert(solution.countCharacters(given_words, given_chars) == expected_answer);

    return 0;
}
