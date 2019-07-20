//#332 Reconstruct Itinerary - https://leetcode.com/problems/reconstruct-itinerary/
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    void dfs(string& airport, unordered_map<string, multiset<string>>& airports, vector<string>& result) {
            while (!airports[airport].empty()) {
                string neighbour = *airports[airport].begin();
                airports[airport].erase(airports[airport].begin());
                dfs(neighbour, airports, result);
            }
            result.push_back(airport);
        }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> airports;
        vector<string> result;
        for(auto ticket : tickets)
        {
            airports[ticket[0]].insert(ticket[1]);
        }
        string airport = "JFK";
        dfs(airport, airports, result);
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution solution;
    vector<vector<string>> given_tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<string> expected_answer = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    assert(solution.findItinerary(given_tickets) == expected_answer);

    given_tickets = {{"JFK", "KUL"}, {"JFK", "NRT"}, {"NRT", "JFK"}};
    expected_answer = {"JFK", "NRT", "JFK", "KUL"};
    assert(solution.findItinerary(given_tickets) == expected_answer);

    return 0;
}
