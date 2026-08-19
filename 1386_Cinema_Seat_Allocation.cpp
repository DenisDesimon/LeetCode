//#1386 Cinema Seat Allocation - https://leetcode.com/problems/cinema-seat-allocation/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> masks;
        for(auto &seat : reservedSeats)
        {
            masks[seat[0] - 1] |= 1 << (seat[1] - 1);
        }
        int result = (n - masks.size()) * 2;
        for(auto &mask : masks)
        {
            bool left = (mask.second & 0b11110) == 0;
            bool mid = (mask.second & 0b1111000) == 0;
            bool right = (mask.second & 0b111100000) == 0;
            if(left && right)
                result += 2;
            else if(left || right || mid)
                result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> givenReservedSeats = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    int givenN = 3;
    int expectedAnswer = 4;
    assert(solution.maxNumberOfFamilies(givenN, givenReservedSeats) == expectedAnswer);

    givenReservedSeats = {{2, 1}, {1, 8}, {2, 6}};
    givenN = 2;
    expectedAnswer = 2;
    assert(solution.maxNumberOfFamilies(givenN, givenReservedSeats) == expectedAnswer);


    return 0;
}
