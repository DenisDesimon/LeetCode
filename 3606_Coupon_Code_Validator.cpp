//#3606 Coupon Code Validator - https://leetcode.com/problems/coupon-code-validator/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
private:
    bool isValid(string code)
    {
        if(code.empty())
            return false;
        for(auto &letter : code)
        {
            if((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') || (letter >= '0' && letter <= '9') || letter == '_')
                continue;
            else
                return false;
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> result;
        unordered_map<string, int> business = {{"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};
        vector<vector<string>> coupons;
        for(int i = 0; i < (int)code.size(); i++)
        {
            if(business.count(businessLine[i]) && isActive[i] && isValid(code[i]))
                coupons.push_back({code[i], businessLine[i]});
        }
        sort(coupons.begin(), coupons.end(), [&](vector<string> &left, vector<string> &right){
            if(business[left[1]] == business[right[1]])
                return left[0] < right[0];
            return business[left[1]] < business[right[1]];
        });
        for(auto &coupon : coupons)
            result.push_back(coupon[0]);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> givenCodes = {"SAVE20", "", "PHARMA5", "SAVE@20"};
    vector<string> givenBusinessLine  = {"restaurant", "grocery", "pharmacy", "restaurant"};
    vector<bool> givenActivities = {true, true, true, true};
    vector<string> expectedAnswer = {"PHARMA5", "SAVE20"};
    assert(solution.validateCoupons(givenCodes, givenBusinessLine, givenActivities) == expectedAnswer);

    givenCodes = {"GROCERY15", "ELECTRONICS_50", "DISCOUNT10"};
    givenBusinessLine  = {"grocery", "electronics", "invalid"};
    givenActivities = {false, true, true};
    expectedAnswer = {"ELECTRONICS_50"};
    assert(solution.validateCoupons(givenCodes, givenBusinessLine, givenActivities) == expectedAnswer);

    return 0;
}
