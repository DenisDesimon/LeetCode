//#3562 Maximum Profit from Trading Stocks with Discounts - https://leetcode.com/problems/maximum-profit-from-trading-stocks-with-discounts/
#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        vector<vector<int>> employeesTree(n);
        for(auto &bossEmp : hierarchy)
            employeesTree[bossEmp[0] - 1].push_back(bossEmp[1] - 1);
        auto dfs = [&](auto &&self, int cur) -> tuple<vector<int>, vector<int>, int>
        {
            int cost = present[cur];
            int halfCost = present[cur] / 2;

            vector<int> boss(budget + 1);
            vector<int> bossHalf(budget + 1);

            vector<int> employees(budget + 1);
            vector<int> employeesHalf(budget + 1);


            int totalCost = cost;


            for(auto employee : employeesTree[cur])
            {
                auto [curEmployees, curEmployeesHalf, employeesCost] = self(self, employee);
                totalCost += employeesCost;
                for(int i = budget; i >= 0; i--)
                {
                    for(int sub = 0; sub <= min(employeesCost, i); sub++)
                    {
                        employees[i] = max(employees[i], employees[i - sub] + curEmployees[sub]);
                        employeesHalf[i] = max(employeesHalf[i], employeesHalf[i - sub] + curEmployeesHalf[sub]);
                    }
                }
            }


            for(int i = 0; i <= budget; i++)
            {
                boss[i] = bossHalf[i] = employees[i];
                if(i >= halfCost)
                    bossHalf[i] = max(employees[i], employeesHalf[i - halfCost] + future[cur] - halfCost);
                if(i >= cost)
                    boss[i] = max(employees[i], employeesHalf[i - cost] + future[cur] - cost);
            }

            return {boss, bossHalf, totalCost};
        };
        return get<0>(dfs(dfs, 0))[budget];
    }
};

int main()
{
    Solution solution;
    int givenN = 2;
    vector<int> givenPresent = {1, 2};
    vector<int> givenFuture = {4, 3};
    vector<vector<int>> givenHierarchy = {{1, 2}};
    int givenBudget = 3;
    int expectedAnswer = 5;
    assert(solution.maxProfit(givenN, givenPresent, givenFuture, givenHierarchy, givenBudget) == expectedAnswer);

    givenN = 3;
    givenPresent = {5, 2, 3};
    givenFuture = {8, 5, 6};
    givenHierarchy = {{1, 2}, {2, 3}};
    givenBudget = 7;
    expectedAnswer = 12;
    assert(solution.maxProfit(givenN, givenPresent, givenFuture, givenHierarchy, givenBudget) == expectedAnswer);

    return 0;
}
