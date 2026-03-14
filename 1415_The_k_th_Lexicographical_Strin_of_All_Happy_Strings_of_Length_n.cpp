//#1415 The k-th Lexicographical String of All Happy Strings of Length n - https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int &k, int curSize = 0, char lastLetter = 'z') {
        if(curSize == n)
            k--;
        else
        {
            for(char i = 'a'; i <= 'c'; i++)
            {
                if(i != lastLetter)
                {
                    string result = getHappyString(n, k, curSize + 1, i);
                    if(k == 0)
                        return string(1, i) + result;
                }
            }
        }
        return "";
    }
};

int main()
{
    Solution solution;
    int givenN = 3;
    int givenK = 9;
    string expectedAnswer = "cab";
    assert(solution.getHappyString(givenN, givenK) == expectedAnswer);

    givenN = 1;
    givenK = 4;
    expectedAnswer = "";
    assert(solution.getHappyString(givenN, givenK) == expectedAnswer);

    return 0;
}
