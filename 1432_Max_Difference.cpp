//#1432 Max Difference You Can Get From Changing an Integer - https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
private: void replace(string &strNum, char x, char y, int start){
        for(int i = start; i < (int)strNum.size(); i++)
        {
            if(strNum[i] == x)
                strNum[i] = y;
        }
    }
public:
    int maxDiff(int num) {
        string strNum = to_string(num);
        string max = strNum, min = strNum;
        for(int i = 0; i < (int)strNum.size(); i++)
        {
            if(strNum[i] != '9')
            {
                replace(max, strNum[i], '9', i);
                break;
            }
        }
        for(int i = 0; i < (int)strNum.size(); i++)
        {
            if(strNum[i] != '1' && strNum[i] != '0')
            {
                replace(min, strNum[i], i == 0 ? '1' : '0', i);
                break;
            }
        }
        return stoi(max) - stoi(min);
    }
};

int main()
{
    Solution solution;
    int given_num = 1101057;
    int expected_answer = 8808050;
    assert(solution.maxDiff(given_num) == expected_answer);

    given_num = 123456;
    expected_answer = 820000;
    assert(solution.maxDiff(given_num) == expected_answer);

    return 0;
}
