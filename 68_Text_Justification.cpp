//#68 Text Justification - https://leetcode.com/problems/text-justification/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int local_width = maxWidth, start = 0;
        for(int i = 0; i < (int)words.size(); i++)
        {
            local_width -= words[i].size();
            if(local_width < 0)
            {
                local_width += words[i].size() + 1;
                int num_slots = i - start - 1, num_spaces = local_width + num_slots;
                result.push_back("");
                if(num_slots == 0)
                    result.back() += string(num_spaces, ' ');
                for(int j = i - 1; j >= start; j--)
                {
                    result.back() = words[j] + result.back();
                    if(num_slots)
                    {
                        result.back() = string(num_spaces / num_slots, ' ') + result.back();
                        num_spaces -= num_spaces / num_slots;
                    }
                    num_slots--;
                }
                local_width = maxWidth - words[i].size();
                start = i;
            }
            local_width--;
        }
        result.push_back("");
        for(int i = start; i < (int)words.size(); i++)
        {
            result.back() += words[i] + ' ';
        }
        result.back().pop_back();
        result.back() += string(maxWidth - result.back().size(), ' ');
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> given_words = {"What", "must", "be", "acknowledgment", "shall", "be"};
    int given_maxWidth = 16;
    vector<string> expected_answer = {"What   must   be",
                                      "acknowledgment  ",
                                      "shall be        "};

    assert(solution.fullJustify(given_words, given_maxWidth) == expected_answer);

    given_words = {"Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"};
    given_maxWidth = 20;
    expected_answer = {"Science  is  what we",
                       "understand      well",
                       "enough to explain to",
                       "a  computer.  Art is",
                       "everything  else  we",
                       "do                  "};

    assert(solution.fullJustify(given_words, given_maxWidth) == expected_answer);

    return 0;
}
