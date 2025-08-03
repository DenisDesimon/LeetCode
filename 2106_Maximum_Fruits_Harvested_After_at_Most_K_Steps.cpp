//#2106 Maximum Fruits Harvested After at Most K Steps - https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int result = 0;
        auto distance = [&](int &left, int &right){
            if(fruits[left][0] >= startPos)
                return fruits[right][0] - startPos;
            if(fruits[right][0] <= startPos)
                return startPos - fruits[left][0];
            return fruits[right][0] - fruits[left][0] + min(startPos - fruits[left][0], fruits[right][0] - startPos);
        };
        int left = 0, right = 0, fruitSum = 0;
        while(right < (int)fruits.size() && fruits[right][0] <= startPos + k)
        {
            fruitSum += fruits[right][1];
            while(left <= right && distance(left, right) > k)
            {
                fruitSum -= fruits[left][1];
                left++;
            }
            result = max(result, fruitSum);
            right++;
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> givenFruits = {{5, 8}, {7, 7}, {8, 7}, {15, 5}, {18, 8}, {19, 3}, {25, 4}, {26, 1}, {34, 10}, {38, 3}, {39, 4}, {40, 5}};
    int givenStarPos = 6;
    int givenK = 19;
    int expectedAnswer = 38;
    assert(solution.maxTotalFruits(givenFruits, givenStarPos, givenK) == expectedAnswer);

    givenFruits = {{0, 3}, {6, 4}, {8, 5}};
    givenStarPos = 3;
    givenK = 2;
    expectedAnswer = 0;
    assert(solution.maxTotalFruits(givenFruits, givenStarPos, givenK) == expectedAnswer);

    return 0;
}
