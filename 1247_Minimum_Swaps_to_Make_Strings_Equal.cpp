//#1247 Minimum Swaps to Make Strings Equal - https://leetcode.com/problems/minimum-swaps-to-make-strings-equal/
#include <iostream>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0, yx = 0;
        for(int i = 0; i < (int)s1.size(); i++)
        {
            if(s1[i] == 'x' && s2[i] == 'y')
                xy++;
            else if(s1[i] == 'y' && s2[i] == 'x')
                yx++;
        }
        if((xy + yx) % 2 != 0)
            return -1;
        else if(xy % 2 == 0)
            return xy / 2 + yx / 2;
        else
            return xy / 2 + yx / 2 + 2;
    }
};

int main()
{
    Solution solution;
    string given_s1 = "xx";
    string given_s2 = "yy";
    int expected_answer = 1;
    assert(solution.minimumSwap(given_s1, given_s2) == expected_answer);

    given_s1 = "xxyyxyxyxx";
    given_s2 = "xyyxyxxxyx";
    expected_answer = 4;
    assert(solution.minimumSwap(given_s1, given_s2) == expected_answer);

    return 0;
}
