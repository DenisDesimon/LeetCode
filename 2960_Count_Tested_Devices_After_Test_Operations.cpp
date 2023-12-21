//#2960 Count Tested Devices After Test Operations - https://leetcode.com/problems/count-tested-devices-after-test-operations/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int result = 0;
        for(auto &battery : batteryPercentages)
        {
            if(battery > result)
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_batteryPercentages = {1, 1, 2, 1, 3};
    int expected_answer = 3;
    assert(solution.countTestedDevices(given_batteryPercentages) == expected_answer);

    given_batteryPercentages = {0, 1, 2};
    expected_answer = 2;
    assert(solution.countTestedDevices(given_batteryPercentages) == expected_answer);

    return 0;
}
