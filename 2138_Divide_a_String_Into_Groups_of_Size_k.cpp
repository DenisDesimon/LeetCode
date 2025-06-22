//#2138 Divide a String Into Groups of Size k - https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        for(int i = 0; i < (int)s.size(); i += k)
            result.push_back(s.substr(i, k));
        result.back() += string(k - result.back().size(), fill);
        return result;
    }
};

int main()
{
    Solution solution;

    string given_s = "abcdefghi";
    int given_k = 3;
    char given_fill = 'x';
    vector<string> expected_answer = {"abc", "def", "ghi"};
    assert(solution.divideString(given_s, given_k, given_fill) == expected_answer);

    given_s = "abcdefghij";
    given_k = 3;
    given_fill = 'x';
    expected_answer = {"abc", "def", "ghi", "jxx"};
    assert(solution.divideString(given_s, given_k, given_fill) == expected_answer);


    return 0;
}
