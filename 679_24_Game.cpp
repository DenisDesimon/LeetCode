//#679 24 Game - https://leetcode.com/problems/24-game/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
private:
    bool isValid(vector<int>& cards){
        double a = cards[0], b = cards[1], c = cards[2], d = cards[3];
        if(isValid(a + b, c, d) || isValid(a - b, c, d) || isValid(a * b, c, d) || isValid(a / b, c, d))
            return true;
        if(isValid(a, b + c, d) || isValid(a, b - c, d) || isValid(a, b * c, d) || isValid(a, b / c, d))
            return true;
        if(isValid(a, b, c + d) || isValid(a, b, c - d) || isValid(a, b, c * d) || isValid(a, b, c / d))
            return true;
        return false;
    }
    bool isValid(double a, double b, double c){
        if(isValid(a + b, c) || isValid(a - b, c) || isValid(a * b, c) || (b && isValid(a / b, c)))
            return true;
        if(isValid(a, b + c) || isValid(a, b - c) || isValid(a, b * c) || (c && isValid(a, b / c)))
            return true;
        return false;
    }
    bool isValid(double a, double b){
        if(abs(a + b - 24.0) < 0.0001 || abs(a - b - 24.0) < 0.0001 || abs(a * b - 24.0) < 0.0001 || (b && abs(a / b - 24.0) < 0.0001))
            return true;
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());
        do{
            if(isValid(cards))
                return true;
        }while(next_permutation(cards.begin(), cards.end()));
        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> givenCards = {4, 1, 8, 7};
    bool expectedAnswer = true;
    assert(solution.judgePoint24(givenCards) == expectedAnswer);

    givenCards = {1, 2, 1, 2};
    expectedAnswer = false;
    assert(solution.judgePoint24(givenCards) == expectedAnswer);

    return 0;
}
