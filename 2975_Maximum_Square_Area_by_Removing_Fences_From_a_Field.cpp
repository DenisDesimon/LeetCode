//#2975 Maximum Square Area by Removing Fences From a Field - https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        long long result = 0;
        unordered_set<int> hash;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        for(int i = 0; i < (int)hFences.size(); i++)
        {
            for(int j = 0; j < (int)hFences.size(); j++)
                hash.insert(abs(hFences[i] - hFences[j]));
        }
        for(int i = 0; i < (int)vFences.size(); i++)
        {
            for(int j = 0; j < (int)vFences.size(); j++)
            {
                if(hash.count(abs(vFences[i] - vFences[j])))
                    result = max(result, (long long)abs(vFences[i] - vFences[j]));
            }
        }
        return result == 0 ? -1 : result * result % (long long)(1e9 + 7);

    }
};

int main()
{
    Solution solution;
    int given_m = 3;
    int given_n = 4;
    vector<int> given_hFences  = {2, 3};
    vector<int> given_vFences  = {2};
    int expected_answer = 4;
    assert(solution.maximizeSquareArea(given_m, given_n, given_hFences, given_vFences) == expected_answer);

    given_m = 6;
    given_n = 7;
    given_hFences  = {2};
    given_vFences  = {4};
    expected_answer = -1;
    assert(solution.maximizeSquareArea(given_m, given_n, given_hFences, given_vFences) == expected_answer);

    return 0;
}
