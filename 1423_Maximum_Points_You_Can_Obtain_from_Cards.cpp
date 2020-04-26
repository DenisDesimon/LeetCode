//#1423 Maximum Points You Can Obtain from Cards - https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left_sum = 0;
        int right_sum = 0;
        for(int i = 0; i < k; i++)
        {
            left_sum += cardPoints[i];
        }
        int result = left_sum;
        for(int i = 0; i < k; i++)
        {
            right_sum += cardPoints[cardPoints.size() - 1 - i];
            left_sum -= cardPoints[k - i - 1];
            result = max(result, right_sum + left_sum);
        }
        return result;
    }
};


int main()
{
    Solution solution;
    vector<int> given_cards = {1, 2, 3, 4, 5, 6, 1};
    int given_k = 3;
    int expected_answer = 12;
    assert(solution.maxScore(given_cards, given_k) == expected_answer);

    given_cards = {9, 7, 7, 9, 7, 7, 9};
    given_k = 7;
    expected_answer = 55;
    assert(solution.maxScore(given_cards, given_k) == expected_answer);

    return 0;
}
