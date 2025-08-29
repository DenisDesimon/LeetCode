//#1751 Maximum Number of Events That Can Be Attended II - https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
private:
    int binarySearch(vector<vector<int>>& events, int currentStart) {
        int left = 0, right = events.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][1] < currentStart) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](vector<int> &left, vector<int> &right){return left[1] < right[1];});
        vector<vector<int>> dp(events.size() + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= (int)events.size(); ++i) {
                    int prev = binarySearch(events, events[i - 1][0]);

                    for (int j = 1; j <= k; ++j) {
                        dp[i][j] = max(dp[i - 1][j], dp[prev + 1][j - 1] + events[i - 1][2]);
                    }
                }

        return dp.back().back();
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> givenEvents = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
    int givenK = 2;
    int expectedAnswer = 10;
    assert(solution.maxValue(givenEvents, givenK) == expectedAnswer);

    givenEvents = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
    givenK = 3;
    expectedAnswer = 9;
    assert(solution.maxValue(givenEvents, givenK) == expectedAnswer);

    return 0;
}
