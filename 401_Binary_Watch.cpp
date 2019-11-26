//#401 Binary Watch - https://leetcode.com/problems/binary-watch/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for(int hours = 0; hours < 12; hours++)
        {
            for(int minutes = 0; minutes < 60; minutes++)
            {
                if(__builtin_popcount(minutes << 4 | hours) == num)
                    result.push_back(to_string(hours) + (minutes < 10 ? ":0" : ":") + to_string(minutes));
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int given_num = 0;
    vector<string> expected_answer = {"0:00"};
    assert(solution.readBinaryWatch(given_num) == expected_answer);

    given_num = 1;
    expected_answer = {"0:01", "0:02", "0:04", "0:08", "0:16", "0:32", "1:00", "2:00", "4:00", "8:00"};
    assert(solution.readBinaryWatch(given_num) == expected_answer);

    return 0;
}
