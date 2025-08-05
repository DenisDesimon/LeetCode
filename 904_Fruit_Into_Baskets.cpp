//#904 Fruit Into Baskets - https://leetcode.com/problems/fruit-into-baskets/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int  result = 0;
       int left = 0, right = 0;
       unordered_map<int, int> baskets;
       while(right < (int)fruits.size())
       {
           baskets[fruits[right]]++;
           right++;
           while(baskets.size() > 2)
           {
               if(--baskets[fruits[left]] == 0)
                   baskets.erase(fruits[left]);
               left++;
           }
           result = max(result, right - left);
       }
       return result;
    }
};

int main()
{
    Solution solution;
    vector<int> givenFruits = {1, 2, 1};
    int expectedAnswer = 3;
    assert(solution.totalFruit(givenFruits) == expectedAnswer);

    givenFruits = {3, 3, 3, 1, 2, 1, 1 ,2, 3, 3, 4};
    expectedAnswer = 5;
    assert(solution.totalFruit(givenFruits) == expectedAnswer);

    return 0;
}
