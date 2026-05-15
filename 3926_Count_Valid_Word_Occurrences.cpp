//#3926 Count Valid Word Occurrences - https://leetcode.com/problems/count-valid-word-occurrences/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s = "";
        for(auto &chunk : chunks)
            s += chunk;
        int n = s.size();
        string cur = "";
        unordered_map<string, int> countStr;
        for(int i = 0; i < n; i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                cur += s[i];
            }
            else if(s[i] == '-' && !cur.empty() && i + 1 < n && s[i + 1] >= 'a' && s[i + 1] <= 'z')
            {
                cur += s[i];
            }
            else
            {
                if(!cur.empty())
                    countStr[cur]++;
                cur = "";
            }
        }
        if(!cur.empty())
            countStr[cur]++;
        vector<int> result;
        for(auto &query : queries)
        {
            result.push_back(countStr[query]);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> givenChunks  = {"m  cq-i "};
    vector<string> givenQueries  = {"m", "cq-i", "nm"};
    vector<int> expectedAnswer = {1, 1, 0};
    assert(solution.countWordOccurrences(givenChunks, givenQueries) == expectedAnswer);

    givenChunks  = {"eh"};
    givenQueries  = {"ehe", "ehm", "eh", "qeh", "sr"};
    expectedAnswer = {0, 0, 1 ,0, 0};
    assert(solution.countWordOccurrences(givenChunks, givenQueries) == expectedAnswer);

    return 0;
}
