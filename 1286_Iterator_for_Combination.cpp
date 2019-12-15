//#1286 Iterator for Combination - https://leetcode.com/problems/iterator-for-combination/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class CombinationIterator {
    string s;
    vector<int> idx;
    int count = 0;
    int n;
    int s_size;

public:
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        n = combinationLength;
        s_size = characters.size();
        for(int i = 0; i < combinationLength; i++)
            idx.push_back(i);
    }

    string next() {
        if(count == 0)
        {
            count++;
            return s.substr(0, n);
        }
        string result;
        for(int i = n - 1; i >= 0; i--)
        {
            if(idx[i] != s_size - n + i)
            {
                idx[i]++;
                for(int j = i + 1; j < n; j++)
                    idx[j] = idx[j - 1] + 1;
                break;
            }
        }
        for(int i = 0; i < n; i++)
            result += s[idx[i]];
        return result;
    }

    bool hasNext() {
        return idx[0] != s_size - n;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main()
{
    string given_s = "abc";
    int given_length = 2;
    CombinationIterator solution(given_s, given_length);
    assert(solution.hasNext() && solution.next() == "ab" && solution.hasNext() && solution.next() == "ac"
           && solution.hasNext() && solution.next() == "bc" && !solution.hasNext());

    return 0;
}
