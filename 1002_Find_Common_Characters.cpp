//#1002 Find Common Characters - https://leetcode.com/problems/find-common-characters/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> result;
        bool if_match;
        unsigned int pos;
        for(int i = 0; i < (int)A[0].length(); i++)
        {
            if_match = true;
            for(int t = 1; t < (int)A.size(); t++)
            {
                pos = A[t].find(A[0][i]);
                if(pos > A[t].length())
                {if_match = false;break;}
                else
                    A[t].erase(A[t].begin() + pos);
            }
            if(if_match)
                result.push_back(string(1,A[0][i]));
        }
        return result;

    }
};

int main()
{
    Solution solution;
    vector<string> given_string = {"bella", "label", "roller"};
    vector<string>  expected_answer = {"e", "l", "l"};
    assert(solution.commonChars(given_string) == expected_answer);


    given_string = {"cool", "lock", "cook"};
    expected_answer = {"c", "o"};
    assert(solution.commonChars(given_string) == expected_answer);

    return 0;
}
