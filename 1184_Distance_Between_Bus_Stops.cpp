//#1184 Distance Between Bus Stops - https://leetcode.com/problems/distance-between-bus-stops/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int result = 0;
        if(destination < start)
            swap(destination, start);
        for(int i = start; i < destination; i++)
            result += distance[i];
        int reversed = 0;
        for(int i = destination; i != start; i = (i + 1) % distance.size())
            reversed += distance[i];
        return min(reversed, result);
    }
};

int main()
{
    Solution solution;
    vector<int> given_distance = {1, 2, 3, 4};
    int given_start = 0;
    int given_dest = 3;
    int expected_answer = 4;
    assert(solution.distanceBetweenBusStops(given_distance, given_start, given_dest) == expected_answer);

    given_distance = {1, 2, 3, 4};
    given_start = 0;
    given_dest = 1;
    expected_answer = 1;
    assert(solution.distanceBetweenBusStops(given_distance, given_start, given_dest) == expected_answer);

    return 0;
}
