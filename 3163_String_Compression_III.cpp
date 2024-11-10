//#3163 String Compression III - https://leetcode.com/problems/string-compression-iii/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string compressedString(string word) {
        string result = "";
        int count = 1;
        for(int i = 1; i < (int)word.size(); i++)
        {
            if(word[i] != word[i - 1] || count > 8)
            {
                result += to_string(count);
                result += word[i - 1];
                count = 1;
            }
            else
                count++;
        }
        result += to_string(count);
        result += word.back();
        return result;
    }
};

int main()
{
    Solution solution;
    string given_word = "abcde";
    string expected_answer = "1a1b1c1d1e";
    assert(solution.compressedString(given_word) == expected_answer);

    given_word = "aaaaaaaaaaaaaabb";
    expected_answer = "9a5a2b";
    assert(solution.compressedString(given_word) == expected_answer);

    return 0;
}
