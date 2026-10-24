//#2409 Count Days Spent Together - https://leetcode.com/problems/count-days-spent-together/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
    int getDayCount(string &date, int *prefix){
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3));
        return prefix[month - 1] + day;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int monthCap[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int prefix[13] = {0};
        for(int i = 1; i < 12; i++)
            prefix[i] = prefix[i - 1] + monthCap[i - 1];
        int startAlice = getDayCount(arriveAlice, prefix);
        int endAlice = getDayCount(leaveAlice, prefix);
        int startBob = getDayCount(arriveBob, prefix);
        int endBob = getDayCount(leaveBob, prefix);
        return max(0, min(endAlice, endBob) - max(startAlice, startBob) + 1);
    }
};

int main()
{
    Solution solution;
    string givenArriveAlice  = "08-15";
    string givenLeaveAlice  = "08-18";
    string givenArriveBob  = "08-16";
    string givenLeaveBob  = "08-19";
    int expectedAnswer = 3;
    assert(solution.countDaysTogether(givenArriveAlice, givenLeaveAlice, givenArriveBob, givenLeaveBob) == expectedAnswer);

    givenArriveAlice  = "10-01";
    givenLeaveAlice  = "10-31";
    givenArriveBob  = "11-01";
    givenLeaveBob  = "12-31";
    expectedAnswer = 0;
    assert(solution.countDaysTogether(givenArriveAlice, givenLeaveAlice, givenArriveBob, givenLeaveBob) == expectedAnswer);

    return 0;
}
