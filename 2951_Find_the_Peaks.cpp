//#2951 Find the Peaks - https://leetcode.com/problems/find-the-peaks/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> result;
        for(int i = 1; i < (int)mountain.size() - 1; i++)
        {
            if(mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
                result.push_back(i);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_mountain = {2, 4, 4};
    vector<int> expected_answer = {};
    assert(solution.findPeaks(given_mountain) == expected_answer);

    given_mountain = {1, 4, 3, 8, 5};
    expected_answer = {1, 3};
    assert(solution.findPeaks(given_mountain) == expected_answer);

    return 0;
}
