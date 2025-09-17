//#2353 Design a Food Rating System  - https://leetcode.com/problems/design-a-food-rating-system/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <cassert>
using namespace std;

class FoodRatings {
private:
    unordered_map<string, set<pair<int, string>>> cuisineFoodRatings;
    unordered_map<string, string> foodCuisine;
    unordered_map<string, int> foodRating;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < (int)foods.size(); i++)
        {
            cuisineFoodRatings[cuisines[i]].insert({-ratings[i], foods[i]});
            foodCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = -ratings[i];
        }
    }

    void changeRating(string food, int newRating) {
        cuisineFoodRatings[foodCuisine[food]].erase({foodRating[food], food});
        cuisineFoodRatings[foodCuisine[food]].insert({-newRating, food});
        foodRating[food] = -newRating;
    }

    string highestRated(string cuisine) {
        return (cuisineFoodRatings[cuisine].begin())->second;
    }
};

int main()
{
    vector<string> givenFoods  = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> givenCuisines  = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> givenRatings  = {9, 12, 8, 15, 14, 7};
    string expectedAnswer = "kimchi";
    FoodRatings solution(givenFoods, givenCuisines, givenRatings);
    assert(solution.highestRated("korean") == expectedAnswer);

    string givenFood = "sushi";
    int givenNewRating = 17;
    solution.changeRating(givenFood, givenNewRating);
    expectedAnswer = "sushi";
    assert(solution.highestRated("japanese") == expectedAnswer);

    return 0;
}
