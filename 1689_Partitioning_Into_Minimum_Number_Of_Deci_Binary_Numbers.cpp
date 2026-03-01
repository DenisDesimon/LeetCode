//#1689 Partitioning Into Minimum Number Of Deci-Binary Numbers - https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int result = 0;
        for(int i = 0; i < (int)n.size(); i++)
        {
            result = max(result, n[i] - '0');
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string givenN = "82734";
    int expectedAnswer = 8;
    assert(solution.minPartitions(givenN) == expectedAnswer);

    givenN = "27346209830709182346";
    expectedAnswer = 9;
    assert(solution.minPartitions(givenN) == expectedAnswer);

    return 0;
}
