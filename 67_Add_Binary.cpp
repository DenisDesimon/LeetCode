//#67 Add Binary - https://leetcode.com/problems/add-binary/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        auto iter_a = a.rbegin();
        auto iter_b = b.rbegin();
        int left = 0;
        while(iter_a != a.rend() || iter_b != b.rend() || left)
        {
            int num = left;
            if(iter_a != a.rend())
                num += *(iter_a++) - '0';
            if(iter_b != b.rend())
                num += *(iter_b++) - '0';
            result.insert(result.begin(), '0' + num % 2);
            left = num / 2;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_a = "11";
    string given_b = "1";
    string expected_answer = "100";
    assert(solution.addBinary(given_a, given_b) == expected_answer);

    given_a = "1010";
    given_b = "1011";
    expected_answer = "10101";
    assert(solution.addBinary(given_a, given_b) == expected_answer);

    return 0;
}
