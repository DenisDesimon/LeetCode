//#135 Candy - https://leetcode.com/problems/candy/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = 0;
        vector<int> candies(ratings.size(), 1);
        for(int i = 1; i < (int)ratings.size(); i++)
        {
            if(ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        }
        result += candies[candies.size() - 1];
        for(int i = ratings.size() - 2; i >= 0; i--)
        {
            if(ratings[i] > ratings[i + 1])
                candies[i] = max(candies[i], candies[i + 1]  + 1);
           result += candies[i];
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> given_ratings = {1, 3, 2, 2, 1};
    int expected_answer = 7;
    assert(solution.candy(given_ratings) == expected_answer);

    given_ratings = {1, 0, 2};
    expected_answer = 5;
    assert(solution.candy(given_ratings) == expected_answer);

    return 0;
}
