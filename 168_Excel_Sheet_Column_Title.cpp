//#168 Excel Sheet Column Title - https://leetcode.com/problems/excel-sheet-column-title/
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while(n)
        {
            n--;
            result.insert(0, string(1, (char)('A' + n % 26)));
            n /= 26;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_n = 701;
    string expected_answer = "ZY";
    assert(solution.convertToTitle(given_n) == expected_answer);

    given_n = 28;
    expected_answer = "AB";
    assert(solution.convertToTitle(given_n) == expected_answer);

    return 0;
}
