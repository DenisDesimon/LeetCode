//#1418 Display Table of Food Orders in a Restaurant - https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant/
#include <iostream>
#include <vector>
#include <map>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, vector<string>, greater<int>> tables;
        map<string, int> food;
        vector<vector<string>> result;
        for(auto& order : orders)
        {
            tables[stoi(order[1])].push_back(order[2]);
            if(!food.count(order[2]))
            {
                food[order[2]] = 0;
            }
        }
        int i = 1;
        for(auto& meal : food)
            meal.second = i++;
        result.resize(tables.size() + 1, vector<string>(food.size() + 1, "0"));
        result[0][0] = "Table";
        for(auto& meal : food)
            result[0][meal.second] = meal.first;
        i = tables.size();
        for(auto& table : tables)
        {
            result[i][0] = to_string(table.first);
            for(auto& order : table.second)
            {
                result[i][food[order]] = to_string(stoi(result[i][food[order]]) + 1);
            }
            i--;
        }
        return result;
    }
};

int main(){

    Solution solution;
    vector<vector<string>> given_orders = {{"David", "3", "Ceviche"}, {"Corina", "10", "Beef Burrito"}, {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"}, {"Carla", "5", "Ceviche"}, {"Rous", "3", "Ceviche"}};
    vector<vector<string>> expected_answer = {{"Table", "Beef Burrito", "Ceviche", "Fried Chicken", "Water"}, {"3", "0", "2", "1", "0"}, {"5", "0", "1", "0", "1"}, {"10", "1", "0", "0", "0"}};
    assert(solution.displayTable(given_orders) == expected_answer);

    return 0;
}
