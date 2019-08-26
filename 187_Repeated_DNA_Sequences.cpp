//#187 Repeated DNA Sequences - https://leetcode.com/problems/repeated-dna-sequences/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_multiset<string> hash;
        vector<string> result;
        for(int i = 0; i < (int)s.size() - 9; i++)
        {
            string item = s.substr(i, 10);
            if(hash.count(item) == 1)
                result.push_back(item);
            hash.insert(item);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string given_dna = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> expected_answer = {"AAAAACCCCC", "CCCCCAAAAA"};
    assert(solution.findRepeatedDnaSequences(given_dna) == expected_answer);

    return 0;
}
