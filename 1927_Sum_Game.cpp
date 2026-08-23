//#1927 Sum Game - https://leetcode.com/problems/sum-game/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        auto countSumQuest = [&](int start, int end){
            int digitSum = 0, countQuest = 0;
            for(int i = start; i < end; i++)
            {
                if(num[i] == '?')
                    countQuest++;
                else
                    digitSum += num[i] - '0';
            }
            return make_pair(digitSum, countQuest);
        };
        auto [firstHalfSum, firstHalfQuest] = countSumQuest(0, n / 2);
        auto [secondHalfSum, secondHalfQuest] = countSumQuest(n / 2, n);
        if((firstHalfQuest + secondHalfQuest) % 2 == 1)
            return true;
        return firstHalfSum - secondHalfSum != (secondHalfQuest - firstHalfQuest) / 2 * 9;
    }
};

int main()
{
    Solution solution;
    string givenNum = "5023";
    bool expectedAnswer = false;
    assert(solution.sumGame(givenNum) == expectedAnswer);

    givenNum = "25??";
    expectedAnswer = true;
    assert(solution.sumGame(givenNum) == expectedAnswer);


    return 0;
}
