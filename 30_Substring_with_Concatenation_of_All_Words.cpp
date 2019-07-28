//#30 Substring with Concatenation of All Words - https://leetcode.com/problems/substring-with-concatenation-of-all-words/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty())
            return {};
        unordered_map<string, int> all_words;
        vector<int> result;
        for(auto &word : words)
            all_words[word]++;
        int size_words = (int)words.size(), size_word = (int)words[0].size();
        for(int i = 0; i < (int)s.size() - size_word * size_words + 1; i++)
        {
            unordered_map<string, int> visited;
            int count = 0;
            for(; count < size_words; count++)
            {
                string cur_word = s.substr(i + count * size_word, size_word);
                if(!(all_words.count(cur_word) && ++visited[cur_word] <= all_words[cur_word]))
                    break;
            }
            if(count == size_words)
                result.push_back(i);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_s = "wordgoodgoodgoodbestword";
    vector<string> given_words = {"word", "good", "best", "good"};
    vector<int> expected_answer = {8};
    assert(solution.findSubstring(given_s, given_words) == expected_answer);

    given_s = "barfoothefoobarman";
    given_words = {"foo", "bar"};
    expected_answer = {0, 9};
    assert(solution.findSubstring(given_s, given_words) == expected_answer);

    return 0;
}
