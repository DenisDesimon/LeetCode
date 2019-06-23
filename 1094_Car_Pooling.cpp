//#1094 Car Pooling - https://leetcode.com/problems/car-pooling/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](vector<int> trip1, vector<int> trip2){return trip1[1] < trip2[1];});
        priority_queue<pair<int, int>> short_trip;
        int sum_pass = 0;
        for(auto trip : trips)
        {
            short_trip.push({-trip[2], trip[0]});
            while(-short_trip.top().first <= trip[1])
            {
                sum_pass -= short_trip.top().second;
                short_trip.pop();
            }
            sum_pass += trip[0];
            if(sum_pass > capacity)
                return false;
        }
        return true;

    }
};

int main()
{
    Solution solution;
    vector<vector<int>> given_trip = {{3 ,2, 7}, {3, 7, 9}, {8, 3, 9}};
    int given_capacity = 11;
    bool expected_answer = true;
    assert(solution.carPooling(given_trip, given_capacity) == expected_answer);

    given_trip = {{9, 3, 4}, {9, 1, 7}, {4, 2, 4}, {7, 4, 5}};
    given_capacity = 23;
    expected_answer = true;
    assert(solution.carPooling(given_trip, given_capacity) == expected_answer);


    return 0;
    }
