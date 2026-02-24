//#3849 Maximum Bitwise XOR After Rearrangement - https://leetcode.com/problems/maximum-bitwise-xor-after-rearrangement/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string maximumXor(string s, string t) {
        int countOnes = 0, countZeroes = 0;
        for(int i = 0; i < (int)t.size(); i++)
        {
            if(t[i] - '0')
                countOnes++;
            else
                countZeroes++;
        }
        string result = "";
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(s[i] - '0')
            {
                if(countZeroes)
                {
                    result += '1';
                    countZeroes--;
                }else
                    result += '0';
            }else
            {
                if(countOnes)
                {
                    result += '1';
                    countOnes--;
                }
                else
                    result += '0';
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenS = "101";
    string givenT = "011";
    string expectedAnswer = "110";
    assert(solution.maximumXor(givenS, givenT) == expectedAnswer);

    givenS = "0101";
    givenT = "1001";
    expectedAnswer = "1111";
    assert(solution.maximumXor(givenS, givenT) == expectedAnswer);

    return 0;
}
