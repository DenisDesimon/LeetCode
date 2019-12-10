//#537 Complex Number Multiplication - https://leetcode.com/problems/complex-number-multiplication/
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int real_a, im_a, real_b, im_b;
        char buff;
        stringstream aa(a), bb(b);
        bb>>real_a>>buff>>im_a;
        aa>>real_b>>buff>>im_b;
        return to_string(real_a * real_b - im_a * im_b) + '+' + to_string(real_a * im_b + im_a * real_b) + 'i';
    }
};

int main()
{
    Solution solution;
    string given_a = "1+1i";
    string given_b = "1+1i";
    string expected_answer = "0+2i";
    assert(solution.complexNumberMultiply(given_a, given_b) == expected_answer);

    given_a = "1+-1i";
    given_b = "1+-1i";
    expected_answer = "0+-2i";
    assert(solution.complexNumberMultiply(given_a, given_b) == expected_answer);

    return 0;
}
