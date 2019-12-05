//#482 License Key Formatting - https://leetcode.com/problems/license-key-formatting/
#include <iostream>
#include <math.h>
#include <cassert>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int idx_of_delim = 0;
        for(int i = 0; i < (int)S.size(); i++)
        {
            if(S[i] != '-')
                S[idx_of_delim++] = S[i];
        }
        if(idx_of_delim == 0)
            return "";
        S.erase(S.begin() + idx_of_delim, S.end());
        int n = S.size();
        int count_delim = ceil((double)n / (double)K) - 1;
        int idx_key = n - 1;
        S += string(count_delim, ' ');
        int count = 0;
        for(int i = S.size() - 1; i >= 0; i--)
        {
            count++;
            if(count == K + 1)
            {
                S[i] = '-';
                count = 0;
            }
            else
            {
                if(isalpha(S[idx_key]))
                    S[i] = toupper(S[idx_key--]);
                else
                    S[i] = S[idx_key--];
            }
        }
        return S;
    }
};

int main()
{
    Solution solution;
    string given_S = "5F3Z-2e-9-w";
    int given_K = 4;
    string expected_answer = "5F3Z-2E9W";
    assert(solution.licenseKeyFormatting(given_S, given_K) == expected_answer);

    given_S = "2-5g-3-J";
    given_K = 2;
    expected_answer = "2-5G-3J";
    assert(solution.licenseKeyFormatting(given_S, given_K) == expected_answer);

    return 0;
}
