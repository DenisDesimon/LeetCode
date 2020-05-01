//#First Bad Version - https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

vector<bool> given_versions;
bool isBadVersion(int version){
    return given_versions[version - 1];
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while(left < right)
        {
            int mid = right + (left - right) / 2;
            if(isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main()
{
    Solution solution;
    given_versions = {false, true};
    int expected_answer = 2;
    assert(solution.firstBadVersion(given_versions.size()) == expected_answer);

    given_versions = {false, false, false, false, true, true, true};
    expected_answer = 5;
    assert(solution.firstBadVersion(given_versions.size()) == expected_answer);

    return 0;
}
