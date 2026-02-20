//#761 Special Binary String - https://leetcode.com/problems/special-binary-string/
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeLargestSpecial(string s) {
        int count = 0, left = 0;
        vector<string> specials;
        for(int right = 0; right < (int)s.size(); right++)
        {
            if(s[right]  - '0')
                count++;
            else
                count--;
            if(count == 0)
            {
                specials.push_back('1' + makeLargestSpecial(s.substr(left + 1, right - left - 1)) + '0');
                left = right + 1;
            }
        }
        sort(specials.begin(), specials.end(), greater<string>());
        string result;
        for(auto &special : specials)
            result += special;
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "11011000";
    string expectedAnswer = "11100100";
    assert(solution.makeLargestSpecial(givenS) == expectedAnswer);

    givenS = "10";
    expectedAnswer = "10";
    assert(solution.makeLargestSpecial(givenS) == expectedAnswer);

    return 0;
}
