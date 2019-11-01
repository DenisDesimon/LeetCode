//#318 Maximum Product of Word Lengths - https://leetcode.com/problems/maximum-product-of-word-lengths/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size(), result = 0;
        vector<int> bit_word(n);
        for(int i = 0; i < n; i++)
        {
            for(auto ch : words[i])
            {
                bit_word[i] |= 1 << (ch - 'a');
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(!(bit_word[i] & bit_word[j]))
                    result = max(result, (int)words[i].size() * (int)words[j].size() );
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> given_words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    int expected_answer = 16;
    assert(solution.maxProduct(given_words) == expected_answer);

    given_words = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    expected_answer = 4;
    assert(solution.maxProduct(given_words) == expected_answer);

    return 0;
}
