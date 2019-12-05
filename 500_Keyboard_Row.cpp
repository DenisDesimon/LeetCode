//#500 Keyboard Row - https://leetcode.com/problems/keyboard-row/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        unordered_set<char> rows[3];
        rows[0] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
        rows[1] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
        rows[2] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};
        for(auto& word : words)
        {
            if(rows[0].count(tolower(word[0])))
            {
                int i = 1;
                for(; i < (int)word.size(); i++)
                {
                    if(!rows[0].count(tolower(word[i])))
                        break;
                }
                if(i == (int)word.size())
                    result.push_back(word);
            }
            else if(rows[1].count(tolower(word[0])))
            {
                int i = 1;
                for(; i < (int)word.size(); i++)
                {
                    if(!rows[1].count(tolower(word[i])))
                        break;
                }
                if(i == (int)word.size())
                    result.push_back(word);
            }
            else
            {
                int i = 1;
                for(; i < (int)word.size(); i++)
                {
                    if(!rows[2].count(tolower(word[i])))
                        break;
                }
                if(i == (int)word.size())
                    result.push_back(word);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> given_words = {"Hello", "Alaska", "Dad", "Peace"};
    vector<string> expected_answer = {"Alaska", "Dad"};
    assert(solution.findWords(given_words) == expected_answer);

    return 0;
}
