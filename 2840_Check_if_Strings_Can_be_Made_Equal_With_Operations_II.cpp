//#2840 Check if Strings Can be Made Equal With Operations II - https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int letterCount[64] = {0};
        for(int i = 0; i < (int)s1.size(); i++)
        {
            int parity = (1 & i) << 5;
            letterCount[parity + (s1[i] - 'a')]++;
            letterCount[parity + (s2[i] - 'a')]--;
        }
        for(auto &count : letterCount)
        {
            if(count != 0)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string givenS1 = "abcdba";
    string givenS2 = "cabdab";
    bool expectedAnswer = true;
    assert(solution.checkStrings(givenS1, givenS2) == expectedAnswer);

    givenS1 = "abe";
    givenS2 = "bea";
    expectedAnswer = false;
    assert(solution.checkStrings(givenS1, givenS2) == expectedAnswer);

    return 0;
}
