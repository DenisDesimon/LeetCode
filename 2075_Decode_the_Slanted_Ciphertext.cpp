//#2075 Decode the Slanted Ciphertext - https://leetcode.com/problems/decode-the-slanted-ciphertext/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int m = n / rows;
        string result;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < rows && i + j * m + j < n; j++)
            {
                result += encodedText[i + j * m + j];
            }
        }
        int i = result.size() - 1;
        for(; i >= 0; i--)
        {
            if(result[i] != ' ')
                break;
        }
        result = result.substr(0, i + 1);
        return result;
    }
};


int main()
{
    Solution solution;
    string givenText = "ch   ie   pr";
    int givenRows = 3;
    string expectedAnswer = "cipher";
    assert(solution.decodeCiphertext(givenText, givenRows) == expectedAnswer);

    givenText = "iveo    eed   l te   olc";
    givenRows = 4;
    expectedAnswer = "i love leetcode";
    assert(solution.decodeCiphertext(givenText, givenRows) == expectedAnswer);


    return 0;
}
