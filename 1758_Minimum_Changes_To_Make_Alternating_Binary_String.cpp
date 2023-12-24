//#1758 Minimum Changes To Make Alternating Binary String - https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int even = 0;
        for(int i = 0; i < (int)s.size(); i++)
        {
            if(i % 2 == 0)
            {
                if(s[i] == '1')
                    even++;
            }
            else
            {
                if(s[i] == '0')
                    even++;
            }
        }
        return min(even, (int)s.size() - even);
        }
};

int main()
{
    Solution solution;
    string given_s = "0100";
    int expected_answer = 1;
    assert(solution.minOperations(given_s) == expected_answer);

    given_s = "1111";
    expected_answer = 2;
    assert(solution.minOperations(given_s) == expected_answer);


    return 0;
}
