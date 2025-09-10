//#1733 Minimum Number of People to Teach  - https://leetcode.com/problems/minimum-number-of-people-to-teach/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int> unspokenFriends;
        for(auto &friendship : friendships)
        {
            unordered_set<int> curUserLang;
            for(auto &lang : languages[friendship[0] - 1])
                curUserLang.insert(lang);
            bool isSpoken = false;
            for(auto &lang : languages[friendship[1] - 1])
            {
                if(curUserLang.count(lang))
                {
                    isSpoken = true;
                    break;
                }
            }
            if(!isSpoken)
            {
                unspokenFriends.insert(friendship[0] - 1);
                unspokenFriends.insert(friendship[1] - 1);
            }

        }
        int mostSpokenLang = 0;
        vector<int> cntLang(n);
        for(auto &curFriend : unspokenFriends){
            for(auto &lang : languages[curFriend])
            {
                cntLang[lang - 1]++;
                mostSpokenLang = max(mostSpokenLang, cntLang[lang - 1]);
            }
        }
        return unspokenFriends.size() - mostSpokenLang;
    }
};

int main()
{
    Solution solution;
    int givenN = 2;
    vector<vector<int>> givenLanguages = {{1}, {2}, {1, 2}};
    vector<vector<int>> givenFriendships = {{1, 2}, {1, 3}, {2, 3}};
    int expectedAnswer = 1;
    assert(solution.minimumTeachings(givenN, givenLanguages, givenFriendships) == expectedAnswer);

    givenN = 3;
    givenLanguages = {{2}, {1, 3}, {1, 2}, {3}};
    givenFriendships = {{1, 4}, {1, 2}, {3, 4}, {2, 3}};
    expectedAnswer = 2;
    assert(solution.minimumTeachings(givenN, givenLanguages, givenFriendships) == expectedAnswer);

    return 0;
}
