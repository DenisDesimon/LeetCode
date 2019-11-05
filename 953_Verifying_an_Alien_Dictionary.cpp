//#953 Verifying an Alien Dictionary - https://leetcode.com/problems/verifying-an-alien-dictionary/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
    bool compare_words(unordered_map<char, int>& alphabet, string word1, string word2){
        for(int i = 0; i < (int)word1.size() && i < (int)word2.size(); i++)
        {
            if(alphabet[word1[i]] > alphabet[word2[i]])
                return false;
            else if(alphabet[word1[i]] < alphabet[word2[i]])
                return true;
        }
        return word1.size() <= word2.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> alphabet;
        for(int i = 0; i < (int)order.size(); i++)
        {
            alphabet[order[i]] = i;
        }
        for(int i = 1; i < (int)words.size(); i++)
        {
            if(!compare_words(alphabet ,words[i - 1], words[i]))
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<string> given_words = {"hello", "leetcode"};
    string given_order = {"hlabcdefgijkmnopqrstuvwxyz"};
    bool expected_answer = true;
    assert(solution.isAlienSorted(given_words, given_order) == expected_answer);

    given_words = {"word", "world", "row"};
    given_order = {"worldabcefghijkmnpqstuvxyz"};
    expected_answer = false;
    assert(solution.isAlienSorted(given_words, given_order) == expected_answer);

    return 0;
}
