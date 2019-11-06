//#966 Vowel Spellchecker - https://leetcode.com/problems/vowel-spellchecker/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
    string replace_vowels(string s, unordered_set<char>& vowels){
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(vowels.count(s[i]))
                s[i] = '*';
        }
        return s;
    }
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> result;
        unordered_set<string> strict_dictionary;
        unordered_map<string, string> vowel_lower_dictionary;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for(auto word : wordlist)
        {
            strict_dictionary.insert(word);
            string word_lower = word;
            transform(word_lower.begin(), word_lower.end(), word_lower.begin(), ::tolower);
            if(!vowel_lower_dictionary.count(word_lower))
                vowel_lower_dictionary[word_lower] = word;
            word_lower = replace_vowels(word_lower, vowels);
            if(!vowel_lower_dictionary.count(word_lower))
                vowel_lower_dictionary[word_lower] = word;
        }
        for(auto query : queries)
        {
            if(strict_dictionary.count(query))
            {
                result.push_back(query);
                continue;
            }
            string word_lower = query;
            transform(word_lower.begin(), word_lower.end(), word_lower.begin(), ::tolower);
            if(vowel_lower_dictionary.count(word_lower))
            {
                result.push_back(vowel_lower_dictionary[word_lower]);
                continue;
            }
            word_lower = replace_vowels(word_lower, vowels);
            if(vowel_lower_dictionary.count(word_lower))
            {
                result.push_back(vowel_lower_dictionary[word_lower]);
                continue;
            }
            result.push_back("");
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> given_wordlist = {"KiTe", "kite", "hare", "Hare"};
    vector<string> given_queries = {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"};
    vector<string> expected_answer = {"kite", "KiTe", "KiTe", "Hare", "hare", "", "", "KiTe", "", "KiTe"};
    assert(solution.spellchecker(given_wordlist, given_queries) == expected_answer);

    return 0;
}
