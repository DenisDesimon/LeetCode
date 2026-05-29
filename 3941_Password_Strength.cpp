//#3941 Password Strength - https://leetcode.com/problems/password-strength/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int passwordStrength(string password) {
        bool lowerCase[26] = {false};
        bool upperCase[26] = {false};
        bool nums[10] = {false};
        bool specials[4] = {false};
        int result = 0;
        for(auto &letter : password)
        {
            if(letter >= 'a' && letter <= 'z')
                lowerCase[letter - 'a'] = true;
            else if(letter >= 'A' && letter <= 'Z')
                upperCase[letter - 'A'] = true;
            else if(letter >= '0' && letter <= '9')
                nums[letter - '0'] = true;
            else
            {
                if(letter == '!')
                    specials[0] = true;
                else if(letter == '@')
                    specials[1] = true;
                else if(letter == '#')
                    specials[2] = true;
                else
                    specials[3] = true;
            }
        }
        for(auto & count : lowerCase)
            result += 1 * count;
        for(auto & count : upperCase)
            result += 2 * count;
        for(auto & count : nums)
            result += 3 * count;
        for(auto & count : specials)
            result += 5 * count;
        return result;
    }
};

int main()
{
    Solution solution;
    string givenPassword = "aA1!";
    int expectedAnswer = 11;
    assert(solution.passwordStrength(givenPassword) == expectedAnswer);

    givenPassword = "bbB11#";
    expectedAnswer = 11;
    assert(solution.passwordStrength(givenPassword) == expectedAnswer);

    return 0;
}
