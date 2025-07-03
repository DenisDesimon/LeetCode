//#838 Push Dominoes - https://leetcode.com/problems/push-dominoes/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        for(int left = 0; left < (int)dominoes.size(); left++)
        {
            if(dominoes[left] == 'R')
            {
                int right = left + 1;
                for(; right < (int)dominoes.size(); right++)
                {
                    if(dominoes[right] == 'R')
                    {
                        dominoes.replace(left, right - left, right - left, 'R');
                        left = right - 1;
                        break;
                    }
                    else if(dominoes[right] == 'L')
                    {
                        dominoes.replace(left, (right + 1 - left) / 2, (right + 1 - left) / 2, 'R');
                        dominoes.replace(left + (right - left) / 2 + 1, (right - left) / 2, (right - left) / 2, 'L');
                        left = right;
                        break;
                    }
                }
                if(right == (int)dominoes.size())
                    dominoes.replace(left, right - left, right - left, 'R');
            }
            else if(dominoes[left] == 'L')
            {
                int farLeft = left - 1;
                for(; farLeft >= 0; farLeft--)
                {
                    if(dominoes[farLeft] == 'L')
                    {
                        dominoes.replace(farLeft, left - farLeft, left - farLeft, 'L');
                        break;
                    }
                }
                if(farLeft == -1)
                    dominoes.replace(0, left, left, 'L');
            }
        }
        return dominoes;
    }
};

int main()
{
    Solution solution;

    string given_dominoes = ".L.R...LR..L..";
    string expected_answer = "LL.RR.LLRRLL..";
    assert(solution.pushDominoes(given_dominoes) == expected_answer);

    given_dominoes = "L.....RR.RL.....L.R.";
    expected_answer = "L.....RRRRLLLLLLL.RR";
    assert(solution.pushDominoes(given_dominoes) == expected_answer);

    return 0;
}
