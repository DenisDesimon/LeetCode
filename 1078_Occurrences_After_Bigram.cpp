//#1078 Occurrences After Bigram - https://leetcode.com/problems/occurrences-after-bigram/
#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result, split;
        stringstream ss(text);
        string token;
        while (getline(ss, token, ' ')) {
            split.push_back(token);
        }
        for(int i = 0; i < (int)split.size() - 1; i++)
        {
            if(split[i] == first && split[i + 1] == second)
            {
                if(i + 2 < (int)split.size())
                result.push_back(split[i + 2]);
            }
        }
        return result;

    }
};

int main()
{
    Solution solution;
    string text = "we will we will rock you", first = "we", second = "will";
    vector<string> expected_answer = {"we", "rock"};
    assert(solution.findOcurrences(text, first, second) == expected_answer);

    text = "alice is a good girl she is a good student", first = "a", second = "good";
    expected_answer = {"girl", "student"};
    assert(solution.findOcurrences(text, first, second) == expected_answer);

    return 0;
}
