//#38 Count and Say - https://leetcode.com/problems/count-and-say/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 2; i <= n; i++)
        {
            int j = 0;
            string temp;
            while(j < (int)result.size())
            {
                int k = j;
                while(k < (int)result.size() && result[j] == result[k])
                    k++;
                temp += to_string(k - j);
                temp += result[j];
                j = k;
            }
            result = temp;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 5;
    string expected_answer = "111221";
    assert(solution.countAndSay(given_n) == expected_answer);

    given_n = 4;
    expected_answer = "1211";
    assert(solution.countAndSay(given_n) == expected_answer);

    return 0;
}
