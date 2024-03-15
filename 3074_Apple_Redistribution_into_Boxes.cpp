//#3074 Apple Redistribution into Boxes - https://leetcode.com/problems/apple-redistribution-into-boxes/description/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sumApples = 0, result = 0;
        for(int &fruit : apple)
            sumApples += fruit;
        sort(capacity.begin(), capacity.end(), [](int a, int b)
        {
            return a > b;
        });
        while(sumApples > 0)
        {
            sumApples -= capacity[result];
            result++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_apple = {1, 3, 2};
    vector<int> given_capacity = {4, 3, 1, 5, 2};
    int expected_answer = 2;
    assert(solution.minimumBoxes(given_apple, given_capacity) == expected_answer);

    given_apple = {5, 5, 5};
    expected_answer = 4;
    given_capacity = {2, 4, 2, 7};
    assert(solution.minimumBoxes(given_apple, given_capacity) == expected_answer);

    return 0;
}
