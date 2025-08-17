//#1323 Maximum 69 Number - https://leetcode.com/problems/maximum-69-number/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string numStr = to_string(num);
        for(int i = 0; i < (int)numStr.size(); i++)
        {
            if(numStr[i] == '6')
            {
                numStr[i] = '9';
                break;
            }
        }
        return stoi(numStr);
    }
};

int main()
{
    Solution solution;
    int givenNum = 9669;
    int expectedAnswer = 9969;
    assert(solution.maximum69Number(givenNum) == expectedAnswer);

    givenNum = 669;
    expectedAnswer = 969;
    assert(solution.maximum69Number(givenNum) == expectedAnswer);

    return 0;
}
